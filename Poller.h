#ifndef MOUDUO_BASE_POLLER_H
#define MOUDUO_BASE_POLLER_H

#include <vector>
#include <unordered_map>

#include "noncopyable.h"
#include "Timestamp.h"

class Channel;
class EventLoop;

class Poller : muduo::noncopyable
{
public:
    using ChannelList = std::vector<Channel*>;

    Poller(EventLoop *loop);
    virtual ~Poller() = default;

    // Provide a unified interface call for all I/O multiplexing.
    virtual Timestamp poll(int timeoutMs, ChannelList* activeChannels) = 0;
    virtual void updateChannel(Channel* channel) = 0;
    virtual void removeChannel(Channel* channel) = 0;

    // Determine if the current channel is in the current poller.
    virtual bool hasChannel(Channel* channel) const;
    
    // EventLoop able to get Default I/O multiplexing interface
    static Poller* newDefaultPoller(EventLoop* loop);
protected:
    // map key:socket_fd, vaule:channel
    using ChannelMap = std::unordered_map<int, Channel*>;
    ChannelMap channels_;
    
private:
    EventLoop* ownerLoop_; // define which EventLoop belong
};


#endif