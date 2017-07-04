#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <signal.h>
#include <ctime>

#include <vector>
#include <thread>
#include <string>
#include <chrono> 
#include "until.h"
#include "hiredis/hiredis.h"

#define MAX_EVENT_NUMBER 50000
int package_number = 0;
std::mutex mtx;

int run = 1;
void HandleSignal(int sig) {
    printf("stop\n");
    printf("signal %d\n", sig);
    run = 0;
}

int64_t current_millis()
{
    struct timeval tv;
    ::gettimeofday(&tv, NULL);
    return (int64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

std::vector<std::thread> threads; 
int testLoop(int thread_num, int port)
{
     
    for(int i = 0; i < thread_num; i++)
    {
        
        std::thread th = std::thread([=]() {
              //int64_t connect_start = current_millis();
              //printf("connect client %d, time=%ld\n", i, connect_start);
              //std::this_thread::sleep_for(std::chrono::seconds(2));
              redisContext *c;
              redisReply *reply;
              const char *hostname = "127.0.0.1";       
              struct timeval timeout = { 1, 500000 }; // 1.5 seconds
              c = redisConnectWithTimeout(hostname, port, timeout);
              //printf("connect client %d done, millisecond=%d\n", i, current_millis() - connect_start);
              if (c == NULL || c->err) {
                  if (c) {
                      printf("Connection error: %s\n", c->errstr);
                      redisFree(c);
                  } else {
                      printf("Connection error: can't allocate redis context\n");
                  }
              }
	      else
	      {
                  int k = 0;
		  while(::run)
		  {
                  std::string city_name =std::to_string(i) + "chengdu"+ std::to_string(k);
                      
                      //GEOADD
         	      reply = (redisReply*)redisCommand(c, 
					      "GEOADD %s %f %f %s", 
					      "sichuan", (double)k, (double)i, 
					      city_name.c_str());
	              assert(reply->integer == 1);
	              //GEOSEARCH

                      //GEODELETE
                      //reply = (redisReply*)redisCommand(c,
                      //                         "ZREM sichuan %s", city_name.c_str());
                     // assert(reply->integer == 1);
                      
                      k++;                    
                      std::lock_guard<std::mutex> lk(mtx);
	              package_number += 1;
		  }
		  reply = (redisReply*)redisCommand(c, "DEL sichuan");
                  freeReplyObject(reply);
               }
               printf("thread stop\n");
        });          
        threads.push_back(std::move(th));
    }
    
}

int test(int thread_num, int port)
{
    // struct timeval t_start;    
    // gettimeofday(&t_start,NULL);    
    // long start = ((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000;  
    
    std::time_t start = std::time(nullptr);
    testLoop(thread_num, port);
    printf("start main \n");
    int prePackage_number = 0;
    std::time_t end;
    while (run) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::lock_guard<std::mutex> lk(mtx); 
        end = std::time(nullptr);
        printf("average QPS : %f , real time QPS : %f , total package %d\n", 
            (package_number) * 1.0 / (end - start), (package_number - prePackage_number) * 1.0 / 2, package_number);  
        prePackage_number = package_number;
    }
    for (auto &th : threads)
       th.join();
}

int main(int argc, char *argv[])
{
    signal(SIGINT, HandleSignal);
    int thread_num = atoi(argv[1]);
    int port = (argc > 2) ? atoi(argv[2]) : 6379;
    test(thread_num, port);
    return 0;
}
