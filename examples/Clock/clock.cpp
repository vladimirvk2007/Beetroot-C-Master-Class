#include "clock.h"

Clock::Clock(ClockTicker& ticker, ClockDisplay& display)
    : ticker_(ticker),
      display_(display)
{
}

bool Clock::initialize()

{
    ticker_.initialize();
    display_.initialize();
    colonOn_ = true;
    display_.setColon(colonOn_);
    initialized_ = true;
    const bool timeSet = display_.setTime(hours_, minutes_);
    const bool refreshed = display_.refresh();
    return timeSet && refreshed;
}

bool Clock::setTime(uint8_t hours, uint8_t minutes)
{
    if (hours > 23 || minutes > 59)
    {
        return false;
    }

    hours_ = hours;
    minutes_ = minutes;
    seconds_ = 0;

    if (!initialized_)
    {
        return true;
    }

    const bool timeSet = display_.setTime(hours_, minutes_);
    const bool refreshed = display_.refresh();
    return timeSet && refreshed;
}

bool Clock::update()
{
    if (!initialized_)
    {
        return false;
    }

    bool success = true;
    if (ticker_.consumeSecondTick())
    {
        colonOn_ = !colonOn_;
        display_.setColon(colonOn_);

        ++seconds_;
        if (seconds_ == 60)
        {
            seconds_ = 0;
            ++minutes_;
            if (minutes_ == 60)
            {
                minutes_ = 0;
                hours_ = static_cast<uint8_t>((hours_ + 1) % 24);
            }
            success = display_.setTime(hours_, minutes_);
        }
    }

    const bool refreshed = display_.refresh();
    return success && refreshed;
}
