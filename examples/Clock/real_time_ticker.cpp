#include "real_time_ticker.h"

void RealTimeTicker::initialize()
{
    nextTick_ = std::chrono::steady_clock::now() + std::chrono::seconds(1);
    initialized_ = true;
}

bool RealTimeTicker::consumeSecondTick()
{
    if (!initialized_)
    {
        return false;
    }

    // Секунда ще не минула
    if (std::chrono::steady_clock::now() < nextTick_)
    {
        return false;
    }

    // Зсуваємо від попереднього моменту, щоб не накопичувати похибку
    nextTick_ += std::chrono::seconds(1);
    return true;
}
