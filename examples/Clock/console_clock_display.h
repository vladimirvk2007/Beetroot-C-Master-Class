#ifndef CONSOLE_CLOCK_DISPLAY_H
#define CONSOLE_CLOCK_DISPLAY_H

#include <stdint.h>

#include "clock_display.h"

class ConsoleClockDisplay : public ClockDisplay
{
public:
    void initialize() override;
    bool setTime(uint8_t hours, uint8_t minutes) override;
    void setColon(bool enabled) override;
    bool refresh() override;
    void blank() override;

private:
    uint8_t hours_ = 0;
    uint8_t minutes_ = 0;
    uint8_t displayedHours_ = 0;
    uint8_t displayedMinutes_ = 0;
    bool colonEnabled_ = true;
    bool displayedColon_ = true;
    bool hasDisplayedTime_ = false;
};

#endif // CONSOLE_CLOCK_DISPLAY_H
