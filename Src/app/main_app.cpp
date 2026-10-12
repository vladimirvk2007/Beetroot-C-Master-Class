#include "main.h"
#include "indicator/seg7_clock_display.h"

static Seg7ClockDisplay clockDisplay;
// Вказівник на абстрактний клас для перевірки поліморфної роботи
static ClockDisplay* display = &clockDisplay;

extern "C" void main_cpp() {
    display->initialize();
    
    uint8_t hours = 12;
    uint8_t minutes = 34;
    bool colonState = true;

    display->setTime(hours, minutes);
    display->setColon(colonState);

    uint32_t lastLedToggle = HAL_GetTick();
    uint32_t lastTimeUpdate = HAL_GetTick();

    while(1) {
        // Періодичне мультиплексування індикатора
        display->refresh();
        HAL_Delay(2);

        // Блимання двокрапкою кожну секунду (імітація годинника)
        if ((HAL_GetTick() - lastTimeUpdate) >= 1000U) {
            colonState = !colonState;
            display->setColon(colonState);
            lastTimeUpdate = HAL_GetTick();
        }

        // Блимання світлодіодом PC13
        if ((HAL_GetTick() - lastLedToggle) >= 500U) {
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
            lastLedToggle = HAL_GetTick();
        }
    }
}

