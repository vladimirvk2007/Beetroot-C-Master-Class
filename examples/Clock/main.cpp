#include "clock.h"

#include <iomanip>
#include <iostream>

class DemoTicker : public ClockTicker
{
public:
    void initialize() override
    {
    }

    bool consumeSecondTick() override
    {
        if (pendingTicks_ == 0)
        {
            return false;
        }

        --pendingTicks_;
        return true;
    }

    void addTicks(unsigned int count)
    {
        pendingTicks_ += count;
    }

private:
    unsigned int pendingTicks_ = 0;
};

class ConsoleClockDisplay : public ClockDisplay
{
public:
    void initialize() override
    {
    }

    bool setTime(uint8_t hours, uint8_t minutes) override
    {
        hours_ = hours;
        minutes_ = minutes;
        return true;
    }

    void setColon(bool enabled) override
    {
        colonEnabled_ = enabled;
    }

    bool refresh() override
    {
        if (!hasDisplayedTime_ || hours_ != displayedHours_ || minutes_ != displayedMinutes_)
        {
            std::cout << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(hours_);
            if (colonEnabled_)
            {
                std::cout << ':';
            }
            std::cout << std::setw(2) << static_cast<unsigned int>(minutes_) << '\n';

            displayedHours_ = hours_;
            displayedMinutes_ = minutes_;
            hasDisplayedTime_ = true;
        }

        return true;
    }

    void blank() override
    {
        hasDisplayedTime_ = false;
    }

private:
    uint8_t hours_ = 0;
    uint8_t minutes_ = 0;
    uint8_t displayedHours_ = 0;
    uint8_t displayedMinutes_ = 0;
    bool colonEnabled_ = true;
    bool hasDisplayedTime_ = false;
};

int main()
{
    DemoTicker ticker;
    ConsoleClockDisplay display;
    Clock clock(ticker, display);

    if (!clock.initialize() || !clock.setTime(12, 33))
    {
        return 1;
    }

    ticker.addTicks(60);
    for (unsigned int second = 0; second < 60; ++second)
    {
        if (!clock.update())
        {
            return 1;
        }
    }

    return 0;
}
