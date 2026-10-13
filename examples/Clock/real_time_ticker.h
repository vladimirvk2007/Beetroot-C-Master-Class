#ifndef REAL_TIME_TICKER_H
#define REAL_TIME_TICKER_H

#include <chrono>

#include "clock_ticker.h"

// Секундний тікер реального часу на основі std::chrono::steady_clock.
class RealTimeTicker : public ClockTicker
{
public:
    // Запускає відлік першої секунди
    void initialize() override;

    // Віддає по одному такту за кожну минулу секунду (пропущені такти накопичуються)
    bool consumeSecondTick() override;

private:
    std::chrono::steady_clock::time_point nextTick_;  // момент наступного такту
    bool initialized_ = false;
};

#endif // REAL_TIME_TICKER_H
