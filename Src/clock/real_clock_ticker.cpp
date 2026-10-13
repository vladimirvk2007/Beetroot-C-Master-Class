#include "clock/real_clock_ticker.h"
#include "main.h"

RealClockTicker::RealClockTicker(uint32_t intervalMs)
    : intervalMs_(intervalMs),
      lastTickMs_(0)
{
}

void RealClockTicker::initialize()
{
    lastTickMs_ = HAL_GetTick();
}

bool RealClockTicker::consumeSecondTick()
{
    const uint32_t now = HAL_GetTick();
    if ((now - lastTickMs_) >= intervalMs_)
    {
        // Додаємо intervalMs_ для збереження рівномірності та уникнення накопичення похибки
        lastTickMs_ += intervalMs_;
        return true;
    }
    return false;
}
