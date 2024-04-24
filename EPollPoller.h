#ifndef MOUDUO_BASE_EPOLLPOLLER_H
#define MOUDUO_BASE_EPOLLPOLLER_H

#include <vector>
#include <sys/epoll.h>

#include "Poller.h"
#include "Timestamp.h"

class EventLoop;
class Channel;

/**
 * How to use epoll?
 * epoll_create => epoll_event
 * epoll_ctl    => add/mod/del
 * epoll_wait
 */

class EPollPoller : public Poller
{
public:
    EPollPoller(EventLoop* loop);
    ~EPollPoller() override;

    // Rewrite base class abstract methods
    Timestamp poll(int timeoutMs, ChannelList* activeChannels) override;
    void updateChannel(Channel* channel) override;
    void removeChannel(Channel* channel) override;


private:
    static const int kInitEventListSize = 16;

    // fill active connect
    void fillActiveChannels(int numEvent, ChannelList* activeChannels) const;
    void update(int operation, Channel* Channel);

    using EventList = std::vector<epoll_event>;

    int epollfd_;
    EventList event_;
};

#endif