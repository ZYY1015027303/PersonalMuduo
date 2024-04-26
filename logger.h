#ifndef MOUDUO_BASE_LOGGER_H
#define MOUDUO_BASE_LOGGER_H

#include <string>

#include "noncopyable.h"

using namespace muduo;

class Logger;

#define LOG_INFO(logmsgFormat, ...) \
    do { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(INFO); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgFormat, ##__VA_ARGS__); \
        logger.logPrint(buf); \
    } while(0);

#ifdef MODE_DEBUG
    #define LOG_DEBUG(logmsgFormat, ...)         \
        do                                       \
        {
            Logger &logger = Logger::instence(); \
            logger.setLogLevel(DEBUG);           \
            char buf[1024] = {0};                \
            snprintf(buf, 1024, logmsgFormat, ##__VA_ARGS__)   \
            logger.logPrint(buf);                \
        } while(0);
#else
    #define LOG_DEBUG(logmsgFormat, ...) 
#endif

#define LOG_ERROR(logmsgFormat, ...) \
    do { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(ERROR); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgFormat, ##__VA_ARGS__); \
        logger.logPrint(buf); \
    } while(0);



#define LOG_FATAL(logmsgFormat, ...) \
    do { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(FATAL); \
        char buf[1024] = {0}; \
        snprintf(buf, sizeof(buf), logmsgFormat, ##__VA_ARGS__); \
        logger.logPrint(buf); \
        exit(-1); \
    } while(0);

// define log level: INFO Debug Error Fatal
enum loglevel
{
    INFO,
    DEBUG,
    ERROR,
    FATAL,
};

class Logger : noncopyable
{
private:
    Logger() {};
    int logLevel_;
public:
    // get Logger instence
    static Logger& instance();

    // set Logger level
    void setLogLevel(int level);

    // write log file
    void logPrint(std::string msg);
    ~Logger();
};

#endif
