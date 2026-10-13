#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

#include "clock_display.h"
#include "clock_ticker.h"

// Годинник: рахує час за секундними тактами і виводить на дисплей лише години й хвилини.
class Clock
{
public:
    // Тікер і дисплей передаються як абстрактні інтерфейси
    Clock(ClockTicker& ticker, ClockDisplay& display);

    // Ініціалізує тікер і дисплей та показує поточний час
    bool initialize();

    // Встановлює час (години 0–23, хвилини 0–59); false, якщо значення некоректні
    bool setTime(uint8_t hours, uint8_t minutes);

    // Викликається в циклі: опитує тікер, рахує час і оновлює дисплей
    bool update();

private:
    ClockTicker& ticker_;
    ClockDisplay& display_;
    uint8_t hours_ = 0;
    uint8_t minutes_ = 0;
    uint8_t seconds_ = 0;
    bool colonOn_ = true;      // поточний стан двокрапки (блимає раз на секунду)
    bool initialized_ = false;
};

#endif // CLOCK_H
