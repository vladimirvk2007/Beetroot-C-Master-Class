#ifndef INDICATOR_SEG7_CLOCK_DISPLAY_H
#define INDICATOR_SEG7_CLOCK_DISPLAY_H

#include "indicator/clock_display.h"
#include "indicator/seg7_display.h"

// Годинниковий індикатор на базі 4-розрядного 7-сегментного дисплея Seg7Display.
class Seg7ClockDisplay : public ClockDisplay
{
public:
    explicit Seg7ClockDisplay(
        const Seg7DisplayConfig& config = SEG7_DISPLAY_DEFAULT_CONFIG);

    // Ініціалізація дисплея
    void initialize() override;

    // Встановлення часу (години 0–23, хвилини 0–59)
    bool setTime(uint8_t hours, uint8_t minutes) override;

    // Керування двокрапкою (розділювач між 2-м та 3-м розрядами)
    void setColon(bool enabled) override;

    // Періодичне оновлення індикації (мультиплексування розрядів)
    bool refresh() override;

    // Гасіння індикатора
    void blank() override;

    // Доступ до внутрішнього Seg7Display (за потреби безпосереднього налаштування)
    Seg7Display& getDisplay();

private:
    Seg7Display display_;
};

#endif // INDICATOR_SEG7_CLOCK_DISPLAY_H
