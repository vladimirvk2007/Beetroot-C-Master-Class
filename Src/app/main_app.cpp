#include "main.h"
#include "indicator/seg7_display.h"

static Seg7Display display;

extern "C" void main_cpp() {
    display.initialize();
    display.setText("aBcD");
    uint32_t lastLedToggle = HAL_GetTick();

    while(1) {
        display.refresh();
        HAL_Delay(2);

        if ((HAL_GetTick() - lastLedToggle) >= 500U) {
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
            lastLedToggle = HAL_GetTick();
        }
    }
}
