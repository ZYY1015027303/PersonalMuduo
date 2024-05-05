#include "Poller.h"
#include "EPollPoller.h"


Poller* Poller::newDefaultPoller(EventLoop* loop)
{
#ifdef POLL_DEFAULT
    return nullptr;
#else
    return new EPollPoller(loop);
#endif
}