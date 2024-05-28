#ifndef MOUDUO_BASE_ACCEPTOR_H
#define MOUDUO_BASE_ACCEPTOR_H

#include <functional>

#include "Socket.h"
#include "Channel.h"
#include "noncopyable.h"
#include "InetAddress.h"

class EventLoop;
class InetAdress;

class Acceptor : muduo::noncopyable
{
public:
    using NewConnectionCallback = std::function<void(int socketfd, const InetAddress&)>;
    Acceptor(EventLoop *loop, const InetAddress &listenAddr, bool reuseport);
    ~Acceptor();

    void setNewConnectCallback(const NewConnectionCallback &cb)
    {
        newConnectionCallback_ = cb;
    }

    bool listenning() const { return listenning_; }
    void listen();
private:
    void handleRead();
    EventLoop *loop_;
    Socket acceptSocket_;
    Channel acceptChannel_;
    NewConnectionCallback newConnectionCallback_;
    bool listenning_;
};



#endif