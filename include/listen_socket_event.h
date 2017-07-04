#ifndef LISTEN_SOCKET_EVENT
#define LISTEN_SOCKET_EVENT
#include <functional>
#include "socket_event.h"
namespace lbs
{
typedef std::function<int(int)> Acceptor; 
class Reactor;
class ListenSocketEvent : public SocketEvent
{
public:
    ListenSocketEvent(Reactor* reactor, int fd, int port, Acceptor acceptor);
	
    virtual ~ListenSocketEvent();

    int init() override;
	
    int onEvent(int event) override; 
    
    void close() override;

private:
    Acceptor acceptor_;
    int port_;
};
}

#endif
