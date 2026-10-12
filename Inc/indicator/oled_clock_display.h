#ifndef INDICATOR_OLED_CLOCK_DISPLAY_H
#define INDICATOR_OLED_CLOCK_DISPLAY_H

#include "indicator/clock_display.h"
#include "oled/oled.h"

// Годинниковий індикатор на базі OLED дисплея.
class OledClockDisplay : public ClockDisplay
{
public:
    // Конструктор приймає налаштований I2C та опціональні налаштування OLED
    explicit OledClockDisplay(I2C_HandleTypeDef *hi2c,
                              const OLED_SettingsTypeDef *settings = nullptr);
    ~OledClockDisplay() override;

    // Ініціалізація дисплея
    void initialize() override;

    // Встановлення часу (години 0–23, хвилини 0–59)
    bool setTime(uint8_t hours, uint8_t minutes) override;

    // Керування двокрапкою
    void setColon(bool enabled) override;

    // Оновлення / перемальовка кадру на OLED
    bool refresh() override;

    // Очищення екрана
    void blank() override;

    // Доступ до дескриптора OLED
    OLED_HandleTypeDef* getOledHandle() const;

private:
    void render();

    I2C_HandleTypeDef *hi2c_;
    OLED_SettingsTypeDef settings_;
    OLED_HandleTypeDef *oled_;

    uint8_t hours_;
    uint8_t minutes_;
    bool colonEnabled_;
    bool isDirty_;
};

#endif // INDICATOR_OLED_CLOCK_DISPLAY_H
