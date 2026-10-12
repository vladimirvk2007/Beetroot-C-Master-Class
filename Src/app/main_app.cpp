#include "main.h"
#include "indicator/oled_clock_display.h"
#include "indicator/seg7_clock_display.h"

// Дисплей на базі I2C OLED (SSD1306):
static I2C_HandleTypeDef hi2c1;
static OledClockDisplay oledClock(&hi2c1);

// Також доступний 7-сегментний дисплей:
static Seg7ClockDisplay seg7Clock;

// Робота через спільний абстрактний інтерфейс ClockDisplay:
static ClockDisplay* display = &oledClock;

extern "C" void main_cpp() {
    display->initialize();

    uint8_t hours = 12;
    uint8_t minutes = 34;
    bool colonState = true;

    display->setTime(hours, minutes);
    display->setColon(colonState);

    uint32_t lastLedToggle = HAL_GetTick();
    uint32_t lastSecondTick = HAL_GetTick();

    while(1) {
        display->refresh();
        HAL_Delay(2);

        // Щосекундне перемикання двокрапки (імітація годинника)
        if ((HAL_GetTick() - lastSecondTick) >= 1000U) {
            colonState = !colonState;
            display->setColon(colonState);
            lastSecondTick = HAL_GetTick();
        }

        // Блимання світлодіодом PC13
        if ((HAL_GetTick() - lastLedToggle) >= 500U) {
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
            lastLedToggle = HAL_GetTick();
        }
    }
}

