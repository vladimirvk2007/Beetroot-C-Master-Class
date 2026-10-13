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
    if (!hasDisplayedTime_ || hours_ != displayedHours_ || minutes_ != displayedMinutes_ ||
        colonEnabled_ != displayedColon_)
    {
        // Redraw in place so the blinking colon doesn't scroll the console.
        std::cout << '\r' << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(hours_)
                  << (colonEnabled_ ? ':' : ' ')
                  << std::setw(2) << static_cast<unsigned int>(minutes_) << std::flush;

        displayedHours_ = hours_;
        displayedMinutes_ = minutes_;
        displayedColon_ = colonEnabled_;
        hasDisplayedTime_ = true;
    }

    return true;
}

void ConsoleClockDisplay::blank()
{
    hasDisplayedTime_ = false;
}
