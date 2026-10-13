#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

#include "clock_display.h"
#include "clock_ticker.h"

class Clock
{
public:
    Clock(ClockTicker& ticker, ClockDisplay& display);

    bool initialize();
    bool setTime(uint8_t hours, uint8_t minutes);
    bool update();

private:
    ClockTicker& ticker_;
    ClockDisplay& display_;
    uint8_t hours_ = 0;
    uint8_t minutes_ = 0;
    uint8_t seconds_ = 0;
    bool colonOn_ = true;
    bool initialized_ = false;
};

#endif // CLOCK_H
