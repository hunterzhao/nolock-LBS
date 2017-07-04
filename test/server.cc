#include <signal.h>
#include <memory>
#include <gperftools/profiler.h>
#include "lbs_server.h"
#include "event_poll.h"
#include "reactor.h"
#include "log.h"

using namespace lbs;
using namespace std;

int run = 1;
void HandleSignal(int sig) {
    printf("stop\n");
    printf("signal %d\n", sig);
    run = 0;
}

int main(int argc, char *argv[])
{
//    ProfilerStart("server.prof");
    GLogHelper loghelper(argv[0]);
    LOG(ERROR) << "server start";
    signal(SIGINT, HandleSignal);
    signal(SIGPIPE, SIG_IGN);
    Reactor* reactor = new Reactor();
	LBSServer* server = new LBSServer(reactor);
    if (server->listen(8899) > 0)
    {
        while(run)
        {
        	reactor->loop();
        }
        //reactor->dryThreadPool();
    }
    delete server;
    delete reactor; 
//    ProfilerStop(); 
	return 0;
}
