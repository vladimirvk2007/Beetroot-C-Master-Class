#include "clock.h"
#include "real_time_ticker.h"

#include <iomanip>
#include <iostream>
#include <windows.h>

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
    RealTimeTicker ticker;
    ConsoleClockDisplay display;
    Clock clock(ticker, display);

    if (!clock.initialize() || !clock.setTime(12, 33))
    {
        return 1;
    }

    while (true)
    {
        if (!clock.update())
        {
            return 1;
        }

        Sleep(10);
    }
}
