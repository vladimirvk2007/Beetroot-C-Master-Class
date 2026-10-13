#ifndef real_time_ticker_H
#define real_time_ticker_H

#include <chrono>

#include "clock_ticker.h"

class RealTimeTicker : public ClockTicker
{
public:
    void initialize() override;
    bool consumeSecondTick() override;

private:
    std::chrono::steady_clock::time_point nextTick_;
    bool initialized_ = false;
};

#endif // real_time_ticker_H
