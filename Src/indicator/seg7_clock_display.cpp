#include "indicator/seg7_clock_display.h"

Seg7ClockDisplay::Seg7ClockDisplay(const Seg7DisplayConfig& config)
    : display_(config)
{
}

// Ініціалізує порти та піни індикатора.
void Seg7ClockDisplay::initialize()
{
    display_.initialize();
}

// Формує 4 символи часу "HHMM" і передає в Seg7Display.
bool Seg7ClockDisplay::setTime(uint8_t hours, uint8_t minutes)
{
    if (hours > 23U || minutes > 59U) {
        return false;
    }

    char timeStr[5];
    timeStr[0] = static_cast<char>('0' + (hours / 10U));
    timeStr[1] = static_cast<char>('0' + (hours % 10U));
    timeStr[2] = static_cast<char>('0' + (minutes / 10U));
    timeStr[3] = static_cast<char>('0' + (minutes % 10U));
    timeStr[4] = '\0';

    return display_.setText(timeStr);
}

// Вмикає або вимикає двокрапку між розрядами 2 і 3.
void Seg7ClockDisplay::setColon(bool enabled)
{
    display_.setColon(enabled);
}

// Викликає мультиплексне оновлення чергового розряду.
bool Seg7ClockDisplay::refresh()
{
    return display_.refresh();
}

// Гасить індикатор.
void Seg7ClockDisplay::blank()
{
    display_.blank();
}

Seg7Display& Seg7ClockDisplay::getDisplay()
{
    return display_;
}
