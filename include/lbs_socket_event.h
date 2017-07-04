#ifndef _LBS_SOCKET_EVENT_H_
#define _LBS_SOCKET_EVENT_H_
#include <functional>
#include <string>
#include "socket_event.h"

namespace lbs
{
class Reactor;
class LBSSocketEvent : public SocketEvent 
{
public:
    typedef std::function<bool(const std::vector<std::string>, std::string&)> Requestor;
    LBSSocketEvent(int fd, Requestor reactor);
    LBSSocketEvent(Reactor* reactor, int fd, Requestor requestor);
    virtual ~LBSSocketEvent();
    
    int  init() override;
    void detectPackage();
    int  onEvent(int event) override; 
    void close() override;
    void setRequestCb(Requestor request) { requestor_ = request;};
    static size_t addHead(char* data, std::string str);

private:
    int  dataIn();
    int  dataOut();

private:
    Requestor requestor_;
};
}

#endif
