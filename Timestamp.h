#ifndef MOUDUO_BASE_TIMESTAMP_H
#define MOUDUO_BASE_TIMESTAMP_H

#include <iostream>
#include <string>

class Timestamp
{
public:
    Timestamp();
    explicit Timestamp(int64_t microSecondsSinceEpoch);

    static Timestamp now();
    std::string toSring() const;
    
private:
    int64_t microSecondsSinceEpoch_;
};


#endif