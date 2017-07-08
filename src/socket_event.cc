#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <functional>
#include <stdio.h>
#include "socket_event.h"
#include "reactor.h"
#include "type.h"
#include "log.h"

namespace lbs
{
SocketEvent::SocketEvent(int fd)
    : fd_(fd),
      in_(new DataBuffer(fd)),
      out_(new DataBuffer(fd)) 
{

}

SocketEvent::SocketEvent(Reactor* reactor, int fd) 
    : reactor_(reactor), 
      fd_(fd),
      in_(new DataBuffer(fd)),
      out_(new DataBuffer(fd)) 
{

}

SocketEvent::~SocketEvent() 
{
    event_ = 0;
    delete in_;
    delete out_;
}

void SocketEvent::closeInNextLoop()
{
    DLOG(WARNING) << "close in next loop";
    reactor_->appendPollTask(std::move(std::bind(&SocketEvent::close, this)));
}

int SocketEvent::setNoBlock()
{
    int opts = ::fcntl(fd_, F_GETFL);
	if (opts < 0)
	{
        DLOG(ERROR) << "fcntl sock failed";
		exit(1);
	}
	opts = opts | O_NONBLOCK;
	if (::fcntl(fd_, F_SETFL, opts) < 0)
	{
		DLOG(ERROR) << "fcntl sock failed";
		exit(1);
	}
    return 1;
}

int SocketEvent::reuseAddress()
{
    int reuse = 1;
    if (::setsockopt(fd_, SOL_SOCKET, 
    	SO_REUSEADDR, &reuse, sizeof(reuse)) > 0)
    {
        DLOG(ERROR) << "exit reuse address";
    	exit(-1);
    }
    return 1;
}

int SocketEvent::send(char* data, size_t n)
{
    //如果用户缓冲区为空先尝试发送，如果不能发送再往用户缓冲区去存
    
    if (n == 0)
    {
        return 1;
    }
    
    if (out_->getLen() == 0)
    {       
        int nwrite = 0;
        while (n > 0)
        {
            nwrite = ::write(fd_, data, n);
            if (nwrite > 0)
            {
                n -= nwrite;
                data += nwrite;
            }

            if (nwrite < 0)
            {
                if (errno == EINTR)
                    continue;
                if (errno == EAGAIN || errno == EWOULDBLOCK)
                    break;
                DLOG(WARNING) << "write failed";
                return -1;
            }
        }
        /* 发送数据over 指定长度数据发完或者缓冲区满了*/
    }
  
    if (out_->append(data, n) < 0)
    {
        DLOG(ERROR) << "buffer is full,append faild";
        return -1;
    }
    return 1;
}

void SocketEvent::setReactor(Reactor* reactor) 
{ 
    if (reactor_ == nullptr) 
    {
        DLOG(INFO) << "reactor is set correct";
        reactor_ = reactor; 
    }
    else 
    {
        DLOG(ERROR) << "reactor is not null";
    }
}
}
