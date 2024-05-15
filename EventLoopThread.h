#ifndef MOUDUO_BASE_EVENTLOOPTHREAD_H
#define MOUDUO_BASE_EVENTLOOPTHREAD_H

#include <functional>
#include <mutex>
#include <condition_variable>
#include <string>

#include "noncopyable.h"
#include "Thread.h"

using namespace muduo;

class EventLoop;

class EventLoopThread : noncopyable
{
public:
    using ThreadInitCallback = std::function<void(EventLoop*)>;
    EventLoopThread(const ThreadInitCallback &cb = ThreadInitCallback(), 
        const std::string &name = std::string());
    ~EventLoopThread();

    EventLoop* startLoop();

private:
    void threadFunc();
    EventLoop *loop_;
    Thread thread_;
    bool exiting_;
    std::mutex mutex_;
    std::condition_variable cond_;
    ThreadInitCallback callback_;
};



#endif