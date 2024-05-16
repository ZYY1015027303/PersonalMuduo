#include "EventLoopThreadPool.h"
#include "EventLoopThread.h"

EventLoopThreadPool::EventLoopThreadPool(EventLoop *baseLoop, const std::string &nameArg)
    : baseLoop_(baseLoop)
    , name_(nameArg)
    , started_(false)
    , numThreads_(0)
    , next_(0)
{

}

EventLoopThreadPool::~EventLoopThreadPool()
{

}

void EventLoopThreadPool::start(const ThreadInitCallback  &cb)
{
    started_ = true;
    for (int i = 0; i < numThreads_; ++i)
    {
        char bufname[name_.size() + 32];
        snprintf(bufname, sizeof bufname, "%s%d", name_.c_str(), i);
        EventLoopThread *t = new EventLoopThread(cb, bufname);
        threads_.push_back(std::unique_ptr<EventLoopThread>(t));
        loops_.push_back(t->startLoop()); // create Thread, bend a new EventLoop
    }

    // only one thread running(baseloop) in server
    if (numThreads_ == 0 && cb) 
    {
        cb(baseLoop_);
    }
}

EventLoop* EventLoopThreadPool::getNextLoop()
{
    EventLoop *loop = baseLoop_;
    
    if (!loops_.empty())
    {
        loop = loops_[next_];
        ++ next_;
        if (next_ >= loops_.size())
        {
            next_ = 0;
        }
    }

    return loop;
}

std::vector<EventLoop*> EventLoopThreadPool::getAllLoop()
{
    if (loops_.empty())
    {
        return std::vector<EventLoop*>(1, baseLoop_);
    }
    else
    {
        return loops_;
    }
}