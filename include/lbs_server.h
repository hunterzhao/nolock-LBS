#ifndef _LBS_SERVER_H_
#define _LBS_SERVER_H_
#include <string>
#include <memory>
#include <vector>
#include <unordered_set>
namespace lbs
{
class Reactor;
class ListenSocketEvent; 
class SocketEvent;
class ThreadPool;
class LBSServer : public std::enable_shared_from_this<LBSServer> 
{
public:
    LBSServer(Reactor* reactor);

    virtual ~LBSServer();
	
    int listen(int port);
    
    int onAccept(int fd);
    
    int doRequest(const std::vector<std::string>& req, std::string& res);

private:
    Reactor* reactor_ = nullptr;
    ThreadPool* thread_pool_ = nullptr;
    ListenSocketEvent* listen_event_ = nullptr;
    int num_client = 0;
    std::unordered_set<std::string> set_;
};
}
#endif
