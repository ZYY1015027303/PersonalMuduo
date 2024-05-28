#include "logger.h"
#include "Socket.h"
#include "InetAddress.h"

#include <unistd.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/tcp.h>

Socket::~Socket()
{
    close(sockfd_);
}

void Socket::bindAddress(const InetAddress &localaddr)
{
    if (bind(sockfd_, (sockaddr*)(localaddr.getSockAddr()), sizeof(sockaddr_in)) != 0)
    {
        LOG_ERROR("bind socket fail %d", sockfd_);
    }
}
void Socket::listen()
{
    if (0 != ::listen(sockfd_, 1024))
    {
        LOG_ERROR("listen socket fail %d", sockfd_);
    }
}
int Socket::accept(InetAddress* peeraddr)
{
    sockaddr_in addr;
    socklen_t len;
    bzero(&addr, sizeof addr);
    
    int connfd = ::accept(sockfd_, (sockaddr*)&addr, &len);
    if (connfd >= 0)
    {
        peeraddr->setSockAddr(addr);
    }

    return connfd;
}

void Socket::shutdownWrite()
{
    if (::shutdown(sockfd_, SHUT_WR) < 0) {
        LOG_ERROR("socket shutdown error\n");
    }
}

void Socket::setTcpDelay(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof optval);
}

void Socket::setReuseAddr(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
}

void Socket::setReusePort(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof optval);
}

void Socket::setKeepAlive(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof optval);
}