#include "Poller.h"


Poller* Poller::newDefaultPoller(EventLoop* loop)
{
#ifdef POLL_DEFAULT
    return nullptr;
#else
    return nullptr;
#endif
}