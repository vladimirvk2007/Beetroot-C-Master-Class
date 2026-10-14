#ifndef CONSOLE_CLOCK_DISPLAY_H
#define CONSOLE_CLOCK_DISPLAY_H

#include <stdint.h>

#include "clock/clock_display.h"

// Консольний дисплей: виводить час у форматі "HH:MM" в один рядок.
class ConsoleClockDisplay : public ClockDisplay
{
public:
    void initialize() override;
    bool setTime(uint8_t hours, uint8_t minutes) override;
    void setColon(bool enabled) override;

    // Перемальовує рядок, лише якщо час або двокрапка змінилися
    bool refresh() override;

    // Скидає стан, щоб наступний refresh() вивів час знову
    void blank() override;

private:
    uint8_t hours_ = 0;
    uint8_t minutes_ = 0;
    uint8_t displayedHours_ = 0;    // що вже виведено на екран
    uint8_t displayedMinutes_ = 0;
    bool colonEnabled_ = true;
    bool displayedColon_ = true;
    bool hasDisplayedTime_ = false;
};

#endif // CONSOLE_CLOCK_DISPLAY_H
