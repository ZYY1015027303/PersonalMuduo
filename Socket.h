#ifndef MOUDUO_BASE_SOCKET_H
#define MOUDUO_BASE_SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "noncopyable.h"


class InetAddress;

class Socket : muduo::noncopyable
{
private:
    const int sockfd_;
public:
    explicit Socket(int sockfd): sockfd_(sockfd)
    {}
    ~Socket();

    int fd() const { return sockfd_; }
    void bindAddress(const InetAddress &localaddr);
    void listen();
    int accept(InetAddress* peeraddr);

    void shutdownWrite();

    void setTcpDelay(bool on);
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void setKeepAlive(bool on);
};


#endif