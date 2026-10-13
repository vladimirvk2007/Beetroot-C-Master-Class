#ifndef REAL_CLOCK_TICKER_H
#define REAL_CLOCK_TICKER_H

#include <stdint.h>
#include "clock/clock_ticker.h"

// Реалізація ClockTicker на основі системного таймера HAL_GetTick()
class RealClockTicker : public ClockTicker
{
public:
    explicit RealClockTicker(uint32_t intervalMs = 1000U);

    void initialize() override;
    bool consumeSecondTick() override;

private:
    uint32_t intervalMs_;
    uint32_t lastTickMs_;
};

#endif // REAL_CLOCK_TICKER_H
