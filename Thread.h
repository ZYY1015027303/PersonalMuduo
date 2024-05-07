#ifndef MOUDUO_BASE_THREAD_H
#define MOUDUO_BASE_THREAD_H

#include <functional>
#include <thread>
#include <memory>
#include <unistd.h>
#include <string>
#include <atomic>

#include "noncopyable.h"

using namespace muduo;

class Thread : noncopyable
{
public:
    using ThreadFunc = std::function<void()>;
    explicit Thread(ThreadFunc, const std::string &name = std::string());
    ~Thread();

    void start();
    void join();

    bool started() const { return started_; }
    bool tid() const { return tid_; }
    const std::string name() { return name_; }
    static int numCreated() { return  numCreated_; }
private:
    void setDefaultName();
    bool started_;
    bool joined_;
    std::shared_ptr<std::thread> pthread_;
    pid_t tid_;
    ThreadFunc func_;
    std::string name_;
    static std::atomic_int numCreated_;
};

#endif