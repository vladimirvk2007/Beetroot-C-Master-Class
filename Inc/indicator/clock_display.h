#ifndef INDICATOR_CLOCK_DISPLAY_H
#define INDICATOR_CLOCK_DISPLAY_H

#include <stdint.h>
#include <stdbool.h>

// Абстрактний базовий клас годинникового індикатора.
// Задає загальний інтерфейс для відображення часу незалежно від типу дисплея (Seg7, OLED тощо).
class ClockDisplay
{
public:
    virtual ~ClockDisplay() = default;

    // Ініціалізація дисплея та периферії
    virtual void initialize() = 0;

    // Встановлення часу (години 0–23, хвилини 0–59)
    virtual bool setTime(uint8_t hours, uint8_t minutes) = 0;

    // Керування двокрапкою (розділювачем годин і хвилин)
    virtual void setColon(bool enabled) = 0;

    // Періодичне оновлення індикації (мультиплексування або відмальовка кадру)
    virtual bool refresh() = 0;

    // Очищення / гасіння індикатора
    virtual void blank() = 0;
};

#endif // INDICATOR_CLOCK_DISPLAY_H
