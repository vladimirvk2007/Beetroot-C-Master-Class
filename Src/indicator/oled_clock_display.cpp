#include "indicator/oled_clock_display.h"
#include <stdio.h>

// Конструктор: зберігає дескриптор I2C і параметри панелі (за замовчуванням 128x64).
OledClockDisplay::OledClockDisplay(I2C_HandleTypeDef *hi2c,
                                   const OLED_SettingsTypeDef *settings)
    : hi2c_(hi2c),
      oled_(nullptr),
      hours_(0),
      minutes_(0),
      colonEnabled_(true),
      isDirty_(false)
{
    if (settings != nullptr) {
        settings_ = *settings;
    } else {
        OLED_SettingsTypeDef def = OLED_SETTINGS_128X64_DEFAULT();
        settings_ = def;
    }
}

// Деструктор: звільняє ресурси та пам'ять дисплея.
OledClockDisplay::~OledClockDisplay()
{
    if (oled_ != nullptr) {
        OLED_Deinit(oled_);
        oled_ = nullptr;
    }
}

// Ініціалізує I2C-шину (якщо не налаштована) та запускає екран OLED.
void OledClockDisplay::initialize()
{
    if (hi2c_ != nullptr && oled_ == nullptr) {
        if (hi2c_->Instance == nullptr) {
            uint32_t speed = (settings_.scl_speed_hz != 0U) ? settings_.scl_speed_hz : 400000U;
            I2C_Init(hi2c_, I2C1, speed);
        }
        OLED_Init(hi2c_, &settings_, &oled_);
        if (oled_ != nullptr) {
            blank();
            isDirty_ = true;
        }
    }
}

// Задає години та хвилини; виставляє прапорець оновлення екрана.
bool OledClockDisplay::setTime(uint8_t hours, uint8_t minutes)
{
    if (hours > 23U || minutes > 59U) {
        return false;
    }

    if (hours_ != hours || minutes_ != minutes) {
        hours_ = hours;
        minutes_ = minutes;
        isDirty_ = true;
    }
    return true;
}

// Вмикає або вимикає розділювальну двокрапку.
void OledClockDisplay::setColon(bool enabled)
{
    if (colonEnabled_ != enabled) {
        colonEnabled_ = enabled;
        isDirty_ = true;
    }
}

// Оновлює зображення на екрані, якщо час або двокрапка змінилися.
bool OledClockDisplay::refresh()
{
    if (oled_ == nullptr) {
        return false;
    }

    if (isDirty_) {
        render();
        isDirty_ = false;
    }
    return true;
}

// Повністю гасить/очищає екран.
void OledClockDisplay::blank()
{
    if (oled_ != nullptr) {
        OLED_Clear(oled_);
    }
}

// Повертає вказівник на дескриптор OLED.
OLED_HandleTypeDef* OledClockDisplay::getOledHandle() const
{
    return oled_;
}

// Формує рядок часу ("ГГ:ХХ" або "ГГ ХХ") і малює його великим шрифтом.
void OledClockDisplay::render()
{
    if (oled_ == nullptr) {
        return;
    }

    char timeStr[6];
    timeStr[0] = static_cast<char>('0' + (hours_ / 10U));
    timeStr[1] = static_cast<char>('0' + (hours_ % 10U));
    timeStr[2] = colonEnabled_ ? ':' : ' ';
    timeStr[3] = static_cast<char>('0' + (minutes_ / 10U));
    timeStr[4] = static_cast<char>('0' + (minutes_ % 10U));
    timeStr[5] = '\0';

    // Очищаємо буфер екрана та друкуємо рядок часу по центру (масштаб 3x)
    OLED_Clear(oled_);
    OLED_Print(oled_, 2, 3, false, timeStr);
}
