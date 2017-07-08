#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <functional>
#include <iostream>
#include <string>
#include "lbs_server.h"
#include "listen_socket_event.h"
#include "lbs_socket_event.h"
#include "geointerface.h"
#include "message.pb.h"
#include "threadpool.h"
#include "log.h"
#include "parse_redis_proto.h"

namespace lbs
{
LBSServer::LBSServer(Reactor* reactor) 
    : reactor_(reactor),
      thread_pool_(new ThreadPool(1))
{
}

LBSServer::~LBSServer() 
{
  if (listen_event_ != nullptr)
    delete listen_event_;

  delete thread_pool_;
    DLOG(INFO) << "lbsserver delete";
}

int LBSServer::listen(int port)
{
    int listen_fd = ::socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd < 0) 
    {
    	return -1;
    }

    listen_event_ = new ListenSocketEvent(reactor_, listen_fd, port,
    	                std::bind(&LBSServer::onAccept, this, std::placeholders::_1));

    if (listen_event_->init() < 0)
    {
        return -1;
    }
    return 1;
}

int LBSServer::onAccept(int fd)
{
    //添加到线程中
    LBSSocketEvent* socket_event = new LBSSocketEvent(fd,
    	                      std::bind(&LBSServer::doRequest, this, 
                              std::placeholders::_1, std::placeholders::_2));
    num_client++;
    thread_pool_->append(socket_event);
    DLOG(INFO) << "no." << num_client;
    return 1;
}

// int LBSServer::request(SocketEvent* socket_event, std::string req)
// {
//     char data[MAX_BUFFER_SIZE];
//     ::memset(data, 0, MAX_BUFFER_SIZE);
//     std::string res;
//     if (doRequest(req, res) < 0)
//     {
//         printf("wrong package\n");
//         return -2;
//     }
//     size_t total_send_len = addHead(data, res);
//     if (socket_event->send(data, total_send_len) < 0)
//     {
//         printf("send error\n");
//         return -1;
//     }
//     return 1;
// }

int LBSServer::doRequest(const std::vector<std::string>& req, std::string& res)
{
    //geo::GeoInterface geo;
    if (req.size() == 0) 
    {
       DLOG(ERROR) << "request is null";
       return -1;
    }
    std::string req_type = req[0];
    std::vector<std::string> res_arry;
    #ifndef NDEBUG
       for (auto str : req)
           std::cout << str << std::endl;
    #endif    
    if (req_type == "SET")
    {
       DLOG(INFO) << "SET";
       set_.insert(req[1]);
       res_arry.push_back(std::string("OK"));
       if (encode(res, 0, res_arry) == false) return -1;
       DLOG(INFO) << " return ok set ok";
       return 1;
    }
    
    geo::GeoInterface geo;
    if (req_type == "GEOADD")
    {
       DLOG(INFO) << "GEOADD request";
       double x = atof(req[1].c_str());
       double y = atof(req[2].c_str());
       if (geo.insertPos(Position(x, y)) > 0)
           res_arry.push_back(std::string("1"));
       else     
           res_arry.push_back(std::string("0"));
       if (encode(res, 2, res_arry) ==false) return -1;
       DLOG(INFO) << "return ok indicate insert ok";
       return 1;
    }
    else if (req_type == "DEL")
    {
       if (geo.deletePos(req[1]) > 0)
           res_arry.push_back(std::string("1"));
       else
           res_arry.push_back(std::string("0"));
       
       if (encode(res, 2, res_arry) ==false) return -1;
       DLOG(INFO) << "delete correct";
    }
     
    else if (req_type == "GEOLIST")
    {
       DLOG(INFO) << "GEOLIST request";
       return 1;
    }
    DLOG(ERROR) << "unknown command";
    return 1;
}
//int LBSServer::doRequest(const std::vector<std::string>& req, std::vector<std::string>& res)
//{
//	geo::GeoInterface geo;
//	ReqProto req_pro;
//    ResProto res_pro;
//    if (req_pro.ParseFromString(req) == false)
//    {
//        LOG(ERROR) << "parse error, " << req.size();
//        return -1;
//    }
//    
//    switch (req_pro.type()) 
//    {
//        /* 消息类型为0 insert query*/
//    	case 0:
//    	{   
//            AddReqProto add_pro = req_pro.addreq();
//            DLOG(INFO) << add_pro.x() << add_pro.y();              
//            if (geo.insertPos(Position(add_pro.x(), add_pro.y())) < 0)  /*thread safe*/
//            {
//                //log error
//                LOG(ERROR) << "insert error";
//                res_pro.set_id(1);
//                res_pro.set_code(-1);
//                assert(res_pro.SerializeToString(&res) == true);
//            }           
//            //printf("insert one pos ok\n"); 
//		    res_pro.set_id(1);
//		    res_pro.set_code(1);
//		    assert(res_pro.SerializeToString(&res) == true);
//    	} 
//    	break;
//        /* 消息类型为1 search query*/
//    	case 1:
//    	{
//    		SearchReqProto search_req = req_pro.searchreq();
//            std::vector<Position> near_pos;
//            if  (!geo.searchPos(Position(search_req.x(), search_req.y()), 
//                      search_req.redius(), near_pos)) /*thread safe*/
//            {
//                //log error
//                LOG(ERROR) << "search error: x : " << search_req.x() 
//                           << " y : " << search_req.y() 
//                           << " r : " << search_req.redius(); 
//                res_pro.set_id(1);
//                res_pro.set_code(-2);
//                assert(res_pro.SerializeToString(&res) == true);
//            }
//            //printf("search one pos ok\n"); 
//            SearchResProto* search_res = new SearchResProto();
//            for (auto c : near_pos) 
//            {
//                NearFriend f;
//                f.set_id(-1);
//                f.set_x(c.x);
//                f.set_y(c.y);
//                *(search_res->add_friends()) = f;
//            }
//            res_pro.set_id(1);
//            res_pro.set_type(1);
//            res_pro.set_code(1);
//            res_pro.set_allocated_searchres(search_res);
//            assert(res_pro.SerializeToString(&res) == true);
//    	}
//        break;
//    }
//    return 1;
//}

}
