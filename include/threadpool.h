#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <time.h>
#include <stdlib.h>
#include <thread>
#include <mutex> 
#include <memory>
#include <functional>
#include <vector>
#include <list>
#include <mutex>
#include <queue>
#include "reactor.h"
#include "socket_event.h"
#include "nocopy.h"
#include "log.h"
/*
*  这是一个线程池
*/
namespace lbs {

class ThreadPool : public NonCopyable
{
public:
    ThreadPool(int thread_number = 4, unsigned int max_requests = 10000)
    : thread_number_(thread_number), 
       max_requests_(max_requests)
    {
        if ((thread_number <= 0) || (max_requests <= 0))
        {
            // error
            printf("thread pool error\n");
        }

        for (int i = 0; i < thread_number; i++) 
        {
            queues_.push_back(std::queue<SocketEvent*>());
            reactors_.push_back(new Reactor());
            std::unique_ptr<std::thread> 
            thread_ptr(new std::thread([=]() {this->run(i);}));
            thread_ptr->detach();
            threads_array_.push_back(std::move(thread_ptr));
        }
    }

    ~ThreadPool()
    {
        threads_array_.clear();
        DLOG(INFO) << "thread pool dry";
        for (auto& reactor : reactors_)
        {
            LOG(ERROR) << "left " << reactor->getHandlerNum();
            delete reactor;
        }
        reactors_.clear();
    }

    /*往请求队列中添加connected socket*/
    bool append(SocketEvent* socket_event)
    {
        int id = rand_r(&seed_) % thread_number_;
        std::lock_guard<std::mutex> lk(mtx_);
        queues_[id].push(socket_event);
        reactors_[id]->notify();
        return true;
    }
    
    void addNewSocketEvent(int id)
    {
        std::lock_guard<std::mutex> lk(mtx_);
        while(!queues_[id].empty())
        {
            SocketEvent* socket_event = queues_[id].front();
            DLOG(INFO) << id <<" thread get one socket event";
            queues_[id].pop();
            socket_event->setReactor(reactors_[id]);
            if (socket_event->init() < 0)
            {
                LOG(ERROR) << id <<" init error";
                socket_event->closeInNextLoop();
            }
        }
    }

private:

    /*所有工作线程在等待条件变量满足后争抢队列中的任务*/
    void run(int id)
    {
        while (true)
        {
            DLOG(INFO) << id <<" new thread reactor loop";
            addNewSocketEvent(id);
            reactors_[id]->loop();
        }
    }

private:
    int thread_number_;  /*线程池中的线程数目*/
    unsigned int max_requests_;   /*请求队列中的允许的最大请求数*/
    std::vector<std::unique_ptr<std::thread>> threads_array_;  /*线程数组*/
    std::vector<std::queue<SocketEvent*>> queues_;  /*任务队列*/
    std::vector<Reactor*> reactors_;
    std::mutex mtx_; /*互斥量*/
    unsigned int seed_ = 123;
};

} //end of namespace lbs

#endif