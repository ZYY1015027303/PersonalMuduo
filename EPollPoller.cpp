#include <errno.h>
#include <unistd.h>  // 或者 #include <fcntl.h>

#include "EPollPoller.h"
#include "logger.h"
#include "Channel.h"

const int kNew = -1;
const int kAdded = 1;
const int KDeleted = 2;

EPollPoller::EPollPoller(EventLoop* loop)
    : Poller(loop)
    , epollfd_(epoll_create1(EPOLL_CLOEXEC))
    , event_(kInitEventListSize)
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

}

// channel update/remove => (father)EventLoop(updateChan) => Poller(update)
void EPollPoller::updateChannel(Channel* channel)
{
    const int index = channel->index_;
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
            if (channels_.find(fd) == channels_.end() ||
                channels_[fd] != channel) ||
                index != kAdded)
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

}

void EPollPoller::fillActiveChannels(int numEvent, ChannelList* activeChannels) const
{

}

void EPollPoller::update(int operation, Channel* Channel)
{

}