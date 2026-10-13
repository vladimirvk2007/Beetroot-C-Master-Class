#include "main.h"
#include "clock/clock.h"
#include "clock/real_clock_ticker.h"
#include "indicator/seg7_clock_display.h"

static RealClockTicker ticker;
static Seg7ClockDisplay seg7Clock;
static Clock clock(ticker, seg7Clock);

extern "C" void main_cpp() {
    clock.initialize();
    clock.setTime(12, 34);

    uint32_t lastLedToggle = HAL_GetTick();

    while(1) {
        clock.update();
        HAL_Delay(2);
    }
}

