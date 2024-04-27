#ifndef MOUDUO_BASE_CHANNEL_H
#define MOUDUO_BASE_CHANNEL_H

#include <functional>
#include <memory>

#include "noncopyable.h"
#include "Timestamp.h"


using namespace muduo;

class EventLoop;

/**
 * Encapsulation socketfd and event (EPOLLIN, EPOLLOUT, poller event)
 * 
*/
class Channel : noncopyable
{
public:
    // typedef std::function<void()> EventCallback;
    // typedef std::function<void(Timestamp)> ReadEventCallback;
    using EventCallback = std::function<void()>;
    using ReadEventCallback = std::function<void(Timestamp)>;

    Channel(EventLoop *loop, int fd);
    ~Channel();

    // handle event 
    void handlEvent(Timestamp receiveTime);

    // set callback func
    void setReadCallback(ReadEventCallback cb) { readCallback_ = std::move(cb); }
    void setWriteCallback(EventCallback cb) { writeCallback_ = std::move(cb); }
    void setCloseCallback(EventCallback cb) { closeCallback_ = std::move(cb); }
    void setErrorCallback(EventCallback cb) { errorCallback_ = std::move(cb); }

    // Prevent callbacks in the channel from being executed even after the channel is removed
    void tie(const std::shared_ptr<void>&);

    int fd() const { return fd_; }
    int events() const { return events_; }
    void set_revent(int revt) { revents_ = revt; }
    

    // set fe event status
    void enableReading() { events_ |= kReadEvent; update(); }
    void disableReading() { events_ &= ~kReadEvent; update(); }
    void enableWriting() { events_ |= kWriteEvent; update(); }
    void disableWriting() { events_ &= ~kWriteEvent; update(); }
    void disableAll() { events_ = kNoneEvent; }

    // get fe event status
    bool isNoneEvent() const { return events_ == kNoneEvent; }
    bool isWriteEvent() const { return events_ & kWriteEvent; }
    bool isReadEvent() const { return events_ & kReadEvent; }

    int index() { return index_; }
    void set_index(int idx) { index_ = idx; }

    EventLoop* ownerLoop() { return loop_; }
    void remove();

private:
    void update();
    void handEventWithGuard(Timestamp receiveTime);

    static const int kNoneEvent;
    static const int kReadEvent;
    static const int kWriteEvent;

    EventLoop *loop_; // event 
    const int fd_;    // listen fd
    int events_;      // rigester event
    int revents_;     // recive event
    int index_;       // a flag of current channel status (kNew kAdded kDelete -1 1 2)

    std::weak_ptr<void> tie_; // fix share_ptr or The existence of monitoring classes
    bool tied_;

    // channel class can get event of FD, then it run cb func;
    ReadEventCallback readCallback_;
    EventCallback writeCallback_;
    EventCallback closeCallback_;
    EventCallback errorCallback_;

};

#endif