#include "console_clock_display.h"

#include <iomanip>
#include <iostream>

void ConsoleClockDisplay::initialize()
{
}

bool ConsoleClockDisplay::setTime(uint8_t hours, uint8_t minutes)
{
    hours_ = hours;
    minutes_ = minutes;
    return true;
}

void ConsoleClockDisplay::setColon(bool enabled)
{
    colonEnabled_ = enabled;
}

bool ConsoleClockDisplay::refresh()
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

void ConsoleClockDisplay::blank()
{
    hasDisplayedTime_ = false;
}
