#include "clock/console_clock_display.h"

#include <cstdio>

void ConsoleClockDisplay::initialize()
{
    hasDisplayedTime_ = false;
}

bool ConsoleClockDisplay::setTime(uint8_t hours, uint8_t minutes)
{
    if (hours > 23U || minutes > 59U) {
        return false;
    }

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
        const int written = std::printf("\r%02u%c%02u",
                                        static_cast<unsigned int>(hours_),
                                        colonEnabled_ ? ':' : ' ',
                                        static_cast<unsigned int>(minutes_));
        if (written < 0 || std::fflush(stdout) == EOF) {
            return false;
        }

        displayedHours_ = hours_;
        displayedMinutes_ = minutes_;
        displayedColon_ = colonEnabled_;
        hasDisplayedTime_ = true;
    }

    return true;
}

void ConsoleClockDisplay::blank()
{
    if (std::printf("\r     \r") < 0 || std::fflush(stdout) == EOF) {
        hasDisplayedTime_ = false;
        return;
    }

    hasDisplayedTime_ = false;
}
