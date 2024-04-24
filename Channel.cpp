#include <sys/epoll.h>

#include "logger.h"
#include "Channel.h"
#include "EventLoop.h"

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = EPOLLIN | EPOLLPRI;
const int Channel::kWriteEvent = EPOLLOUT;

Channel::Channel(EventLoop *loop, int fd)
    : loop_(loop)
    , fd_(fd)
    , events_(0)
    , revents_(0)
    , index_(-1)
    , tied_(false)
{}

Channel::~Channel()
{
}

void Channel::tie(const std::shared_ptr<void> &obj)
{
    tie_ = obj;
    tied_ = true;
}

/**
 * when channel fd event, update poller fd event
 * EventLoop => ChannelList Poller. (Channel and Poller are correlated and independent)
 */
void Channel::update()
{
    // TODO
    // loop_->updateChannel(this);
}

// Delete current Channel
void Channel::remove()
{
    // TODO
    // loop_->removeChannel(this);
}

void Channel::handlEvent(Timestamp receiveTime)
{
    if (tied_)
    {
        std::shared_ptr<void> guard = tie_.lock(); // weak -> strong
        if (guard)
        {
            handEventWithGuard(receiveTime);
        }
    }
    else
    {
        handEventWithGuard(receiveTime);
    }
}

void Channel::handEventWithGuard(Timestamp receiveTime)
{
    LOG_INFO("Channel event handle revent(%d)\n", revents_);
    if ((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN))
    {
        if (closeCallback_) 
        {
            closeCallback_();
        }
    }

    if (revents_ & EPOLLERR)
    {
        if (errorCallback_) 
        {
            errorCallback_();
        }
    }

    if (revents_ & EPOLLOUT)
    {
        if (writeCallback_)
        {
            writeCallback_();
        }
    }

    return;
}