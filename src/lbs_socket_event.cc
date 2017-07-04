#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <iostream>
#include "reactor.h"
#include "lbs_socket_event.h"
#include "type.h"
#include "log.h"
#include "parse_redis_proto.h"

namespace lbs
{
LBSSocketEvent::LBSSocketEvent(int fd, Requestor requestor)
    : SocketEvent(fd),
      requestor_(requestor)
{
    
}

LBSSocketEvent::LBSSocketEvent(Reactor* reactor, int fd, Requestor requestor)
    : SocketEvent(reactor, fd), 
      requestor_(requestor)
{}

LBSSocketEvent::~LBSSocketEvent()
{
    //printf("lbs socket event delete\n");
}

int LBSSocketEvent::init()
{
    setNoBlock();

    if (reactor_->registerHandler(this, EVENT_IN | EVENT_OUT) < 0) 
    {
    	return -1;
    }
    return 1;
}

int LBSSocketEvent::onEvent(int event)
{
    if (event & EVENT_HUP)
    {
        LOG(ERROR) << "hup";
        closeInNextLoop();
        return -1;
    }
    if (event & EVENT_ERR)
    {
        DLOG(INFO) << "peer reset";
        closeInNextLoop();
        return -1;
    }
    
    //can write, write first, read second
    if (event & EVENT_OUT)
    {
        DLOG(INFO) << "event out";
        if (dataOut() < 0)
        {
            closeInNextLoop();
            return -1;
        }
    }

    if (event & EVENT_IN)
    {
        DLOG(INFO) << "event in";
        if (dataIn() < 0)
        {
        	closeInNextLoop();
            return -1;
        }
    }
    return 1;
}

void LBSSocketEvent::close()
{
    //DLOG(ERROR) << "remove event";
    reactor_->removeHandler(this);
    ::close(fd_);
    delete this;
}

int LBSSocketEvent::dataIn()
{
    //将新到来的数据添加到buffer in 缓冲区
    if (in_->readFromFd() < 0)
    {
         return -1;
    }
    detectPackage();
    return 1;
}

int LBSSocketEvent::dataOut()
{
    //buffer out 缓冲区数据尽可能发送出去
    if (out_->writeToFd() < 0)
    {
    	return -1;
    }
    return 1;
}

void LBSSocketEvent::detectPackage()
{
    while(1)
    {
       std::vector<std::string> package_req_content;
       std::string package_res_content;
       
       int package_req_len = 0;
       if (decode(in_->begin(), in_->getLen(), package_req_len, package_req_content) == false)
       {
           DLOG(WARNING) << "wrong decode wait next data";
           break;
       }
       in_->moveStart(package_req_len);

       DLOG(INFO) << in_->getLen();
       in_->copy2Left(package_req_len);       
       DLOG(INFO) << "copy to left" << package_req_len << "space left" << in_->getLen();
       if (requestor_(package_req_content, package_res_content) < 0)
       {
           LOG(ERROR) << "wrong package";
           continue;
       }

       char data[MAX_BUFFER_SIZE];
       std::copy(package_res_content.begin(), package_res_content.end(), data);
       DLOG(INFO) << "try to send " << package_res_content.size();
       if (send(data, package_res_content.size()) < 0)
       {
           DLOG(WARNING) << "send error";
           closeInNextLoop();
           return;
       }
    }    
    reactor_->modifyHandler(this, EVENT_IN | EVENT_OUT);
}

//void LBSSocketEvent::detectPackage()
//{
//    //检测包头
//    uint32_t msg_head;
//    int ret = 0;
//    size_t  already_parse_len = 0;
//    char data[MAX_BUFFER_SIZE];
//    while ((ret = (in_->tryReadNBytes(sizeof(uint32_t), (char*)&msg_head))) > 0)
//    {
//        size_t full_package_len = ::ntohl(msg_head);
//        DLOG(INFO) << "next message is " << full_package_len << " long";
//        already_parse_len = 0;
//    	if (in_->getLen() < full_package_len + sizeof(uint32_t))
//        {
//            DLOG(WARNING) << "buffer len " << in_->getLen() << " ,package need to wait";
//    	    break;
//        }
//        else
//        {
//    	    //包是完整的, remove head
//            in_->moveStart(sizeof(uint32_t));
//            already_parse_len += full_package_len + sizeof(uint32_t);
//            //::memset(data, 0, MAX_BUFFER_SIZE);
//            if (in_->readNBytes(full_package_len, data) < 0)
//                closeInNextLoop();
//            std::string req(data, full_package_len);
//            std::string res;
//            if (requestor_(req, res) < 0)
//            {
//                LOG(ERROR) << "wrong package";
//                continue;
//            }
//            
//            //::memset(data, 0, MAX_BUFFER_SIZE);
//            size_t total_send_len = addHead(data, res);
//            if (send(data, total_send_len) < 0)
//            {
//                DLOG(WARNING) << "send error";
//                closeInNextLoop();
//                return;
//            }
//    	}
//        in_->copy2Left(already_parse_len);
//        DLOG(WARNING) << "copy to start " << already_parse_len;
//    }
//    if (ret == -2)
//    {
//        //read error
//        closeInNextLoop();
//        return;
//    }  //read not enough
//    DLOG(INFO) << "wait next data stream";
//    reactor_->modifyHandler(this, EVENT_IN | EVENT_OUT);
//}

size_t LBSSocketEvent::addHead(char* data, std::string str)
{
    size_t data_len = str.size(); 
    uint32_t dataSendLen = ::htonl(data_len);
    ::memcpy(data, &dataSendLen, sizeof(uint32_t));
    std::copy(str.begin(), str.end(), data + sizeof(uint32_t));
    data_len += sizeof(uint32_t);
    data[data_len] = '\0';
    return data_len;
}
}
