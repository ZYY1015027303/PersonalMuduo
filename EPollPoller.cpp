#include <errno.h>
#include <unistd.h>  // 或者 #include <fcntl.h>
#include <string.h>
#include <assert.h>

#include "EPollPoller.h"
#include "logger.h"
#include "Channel.h"

const int kNew = -1;
const int kAdded = 1;
const int KDeleted = 2;

EPollPoller::EPollPoller(EventLoop* loop)
    : Poller(loop)
    , epollfd_(epoll_create1(EPOLL_CLOEXEC))
    , events_(kInitEventListSize)
{  
    if (epollfd_ < 0) 
    {
        LOG_FATAL("epoll_create error: %d\n", errno);
    }
}

EPollPoller::~EPollPoller()
{
    ::close(epollfd_);
}

Timestamp EPollPoller::poll(int timeoutMs, ChannelList* activeChannels)
{
    LOG_DEBUG("fd total count:%d\n", channels_.size());
    
    int numEvents = ::epoll_wait(epollfd_, &*events_.begin(), 
                                    static_cast<int> (events_.size()),
                                    timeoutMs);
    int saveErrorno  = errno;
    Timestamp now(Timestamp::now());

    if (numEvents > 0) 
    {
        LOG_DEBUG("%d event happend\n", numEvents);
        fillActiveChannels(numEvents, activeChannels);
        if (numEvents == events_.size()) 
        {
            events_.resize(events_.size() * 2);
        }
    }
    else if (numEvents == 0) 
    {
        LOG_DEBUG("timeout /n");
    }
    else
    {
        if ( saveErrorno != EINTR )
        {
            errno = saveErrorno;
            LOG_ERROR("EPollPolle::poll() error\n");
        }
    }

    return now;
}

// channel update/remove => (father)EventLoop(updateChan) => Poller(update)
void EPollPoller::updateChannel(Channel* channel)
{
    const int index = channel->index();
    const int fd = channel->fd();
    LOG_INFO("index = %d, fd = %d\n", index, fd);
    if (index == kNew || index == KDeleted)
    {

        if (index == kNew)
        {
            if (channels_.find(fd) == channels_.end()) 
            {
                channels_[fd] = channel;
            }
            else 
            {
                if (channels_.find(fd) != channels_.end()) 
                {

                }
                if (channels_[fd] == channel) 
                {

                }
            }
            channel->set_index(kAdded);
            update(EPOLL_CTL_ADD, channel);
        }
        else
        {
            if ( channels_.find(fd) == channels_.end()||
                channels_[fd] != channel ||
                index != kAdded )
            {
                LOG_FATAL("error %d\n", errno);
                return;
            }
            if (channel->isNoneEvent()) 
            {
                update(EPOLL_CTL_DEL, channel);
                channel->set_index(KDeleted);
            }
            else
            {
                update(EPOLL_CTL_MOD, channel);
            }
        }
    }
}

void EPollPoller::removeChannel(Channel* channel)
{
    int fd = channel->fd();
    assert(channels_.find(fd) != channels_.end());
    assert(channels_[fd] = channel);
    assert(channels_[fd]->isNoneEvent());
    int index = channel->index();
    assert(index == kAdded || index == KDeleted);
    channels_.erase(fd);

    if (index == kAdded) 
    {
        update(EPOLL_CTL_DEL, channel);
    }
    channel->set_index(kNew);
}

void EPollPoller::fillActiveChannels(int numEvent, ChannelList* activeChannels) const
{
    for (int i = 0; i < numEvent; i ++)
    {
         Channel* channel = static_cast<Channel*> (events_[i].data.ptr);
         channel->set_revent(events_[i].events);
         activeChannels->push_back(channel);
    }
}

// update Channel  epoll_ctl: add/del/mod
void EPollPoller::update(int operation, Channel* channel)
{
    struct epoll_event event;
    memset(&event, 0, sizeof event);
    event.events = channel->events();
    event.data.ptr = channel;
    int fd = channel->fd();

    if (::epoll_ctl(epollfd_, operation, fd, &event) < 0)
    {
        if (operation == EPOLL_CTL_DEL)
        {
            LOG_INFO("epoll oper = %d, fd = %d\n", operation, fd);
        }
        else
        {
            LOG_FATAL("epoll oper = %d, fd = %d\n", operation, fd);
        }
        
    } 
}