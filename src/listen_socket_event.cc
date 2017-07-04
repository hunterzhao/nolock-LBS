#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include "listen_socket_event.h"
#include "type.h"
#include "reactor.h"
#include "log.h"

namespace lbs
{
ListenSocketEvent::
ListenSocketEvent(Reactor* reactor, int fd, int port, Acceptor acceptor)
    : SocketEvent(reactor, fd),
      port_(port), 
      acceptor_(acceptor)  
{}	

ListenSocketEvent::~ListenSocketEvent() {}

int ListenSocketEvent::init()
{
    setNoBlock();
    reuseAddress();
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    socklen_t addr_len = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port_);

    if (::bind(fd_, (struct sockaddr *)&addr, addr_len)) 
    {
         return -1;
    }

    if (::listen(fd_, 20000)) 
    {
        return -1;
    }

    reactor_->registerHandler(this, EVENT_IN, false); //LT
    return 1;
}

int ListenSocketEvent::onEvent(int event)
{
    if (event & EVENT_IN)
    {
    	int i = 0;
	    while (i < 10000)  //LT
	    {
	    	i++;
	    	int fd = ::accept(fd_, nullptr, nullptr);
			if (fd < 0) {
				if (errno == EINTR || errno == ECONNABORTED)
					continue;
				if (errno == EAGAIN || errno == EWOULDBLOCK)
					break;
				//error
				return false;
			} else {
				if (acceptor_(fd) < 0)
					return false;
			}
	    }
    }
    return 1;
}
    
void ListenSocketEvent::close()
{
    reactor_->removeHandler(this);
    ::close(fd_);
}

}
