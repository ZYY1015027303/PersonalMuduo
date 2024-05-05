#ifndef MOUDUO_BASE_EVENTLOOP_h
#define MOUDUO_BASE_EVENTLOOP_h

#include <functional>
#include <vector>
#include <atomic>
#include <memory>
#include <mutex>

#include "noncopyable.h"
#include "Timestamp.h"
#include "CurrentThread.h"


class Channel;
class Poller;

// include channel Poller(like epoll)
class EventLoop : muduo::noncopyable
{
public:
    using Functor = std::function<void()>;

    EventLoop();
    ~EventLoop();

    void loop(); /* start event Loop */
    void quit(); /* quit event Loop */

    Timestamp pollReturnTime() const { return pollReturnTime_; }
    
    void runInLoop(Functor cb); /* Execute cb in Current loop */
    void queueInLoop(Functor cb); /* Execute cb in Current queue */
   
    void wakeup(); /* wakeup loop Thread */

    // EventLoop => Poller
    void updateChannel(Channel* channel);
    void removeChannel(Channel* channel);
    bool hasChannel(Channel* channel);

    // judge EventLoop Obj whether in owner Thread
    bool isInLoopThread() const { threadId_ == CurrentThread::tid(); }

private:
    void handleRead();
    void doPendingFunctors(); /* Execute cb*/

    using ChannelList = std::vector<Channel*>;

    std::atomic_bool looping_; /* atomic CAS */
    std::atomic_bool quit_; /* flag quit Loop*/

    const pid_t threadId_; // mark current Thread id
    Timestamp pollReturnTime_; /*poller return  activeEvent time*/
    std::unique_ptr<Poller> poller_;

    int wakeupFd_; // When mainloop obtains a user's channel, select an sbloop to process the channel
    std::unique_ptr<Channel> wakeupChannel_;

    ChannelList activeChannels_;
    Channel *currentActiveChannel_;

    std::atomic_bool callingPendingFunctors_; /*Mark whether the current loop has a callback function that needs to be executed*/
    std::vector<Functor> pendingFunctiors_; /*store cb func*/
    std::mutex mutex_;
}; 

#endif