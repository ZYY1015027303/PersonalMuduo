#include <iostream>

#include "logger.h"

// get logger instence
Logger& Logger::instance()
{
    static Logger logger;
    return logger;
}
// set logger level
void Logger::setLogLevel(int level)
{
    logLevel_ = level;
}

// write log file
void Logger::logPrint(std::string msg)
{
    switch (logLevel_)
    {
    case INFO:
        std::cout << "[INFO]";
        break;
    case DEBUG:
        std::cout << "[DEBUG]";
        break;
    case ERROR:
        std::cout << "[ERROR]";
        break;
    case FATAL:
        std::cout << "[FATAL]";
        break;
    default:
        break;
    }

    std::cout<< msg << std::endl;

    return;
}