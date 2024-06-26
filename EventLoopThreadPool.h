#ifndef MOUDUO_BASE_EVENTLOOPTHREADPOOL_H
#define MOUDUO_BASE_EVENTLOOPTHREADPOOL_H

#include <functional>
#include <string>
#include <memory>
#include <vector>

#include "noncopyable.h"
#include "Thread.h"

using namespace muduo;

class EventLoop;
class EventLoopThread;

class EventLoopThreadPool : noncopyable
{
public:
    using ThreadInitCallback = std::function<void(EventLoop*)>;
    EventLoopThreadPool(EventLoop *baseLoop, const std::string &nameArg);
    ~EventLoopThreadPool();

    void setThreadNum(int numThreads) { numThreads_ = numThreads; }

    void start(const ThreadInitCallback  &cb = ThreadInitCallback());

    EventLoop* getNextLoop();

    std::vector<EventLoop*> getAllLoop();

    bool started() { return  started_; }
    const std::string name() const { return name_; }

private:
    EventLoop *baseLoop_;
    std::string name_;
    bool started_;
    int numThreads_;
    int next_;
    std::vector<std::unique_ptr<EventLoopThread>> threads_;
    std::vector<EventLoop*> loops_;
    

};
#endif