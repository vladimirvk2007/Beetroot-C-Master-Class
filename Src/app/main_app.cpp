#include "main.h"
#include "clock/clock.h"
#include "clock/real_clock_ticker.h"
#include "indicator/oled_clock_display.h"
#include "indicator/seg7_clock_display.h"

static RealClockTicker ticker;

// I2C дескриптор та годинниковий дисплей на базі OLED
static I2C_HandleTypeDef hi2c1;
static OledClockDisplay oledClock(&hi2c1);

// Також доступний 7-сегментний годинниковий дисплей:
// static Seg7ClockDisplay seg7Clock;

static Clock clock(ticker, oledClock);

extern "C" void main_cpp() {
    clock.initialize();
    clock.setTime(12, 34);

    uint32_t lastLedToggle = HAL_GetTick();

    while(1) {
        clock.update();
        HAL_Delay(10);

        if ((HAL_GetTick() - lastLedToggle) >= 500U) {
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
            lastLedToggle = HAL_GetTick();
        }
    }
}


