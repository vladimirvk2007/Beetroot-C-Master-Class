#include "main.h"
#include "indicator/seg7.h"

#define SEGMENT_PORT GPIOA
#define SEGMENT_A_GPIO GPIO_PIN_5
#define SEGMENT_B_GPIO GPIO_PIN_4
#define SEGMENT_C_GPIO GPIO_PIN_3
#define SEGMENT_D_GPIO GPIO_PIN_2
#define SEGMENT_E_GPIO GPIO_PIN_1
#define SEGMENT_F_GPIO GPIO_PIN_0
#define SEGMENT_G_GPIO GPIO_PIN_6
#define SEGMENT_DP_GPIO GPIO_PIN_7
#define IDICATOR_A1 GPIO_PIN_8
#define IDICATOR_A2 GPIO_PIN_9
#define IDICATOR_A3 GPIO_PIN_10
#define IDICATOR_A4_PORT GPIOB
#define IDICATOR_A4 GPIO_PIN_3

static const SevenSegmentPins segmentPins = {
    SEGMENT_A_GPIO, SEGMENT_B_GPIO, SEGMENT_C_GPIO, SEGMENT_D_GPIO,
    SEGMENT_E_GPIO, SEGMENT_F_GPIO, SEGMENT_G_GPIO, SEGMENT_DP_GPIO,
};

static Seg7 indicators[] = {
    {SEGMENT_PORT, segmentPins, GPIOA, IDICATOR_A1},
    {SEGMENT_PORT, segmentPins, GPIOA, IDICATOR_A2},
    {SEGMENT_PORT, segmentPins, GPIOA, IDICATOR_A3, true},
    {SEGMENT_PORT, segmentPins, IDICATOR_A4_PORT, IDICATOR_A4},
};

static const char displayCharacters[] = {'A', 'b', 'C', 'd'};

extern "C" void main_cpp() {
    __HAL_RCC_GPIOB_CLK_ENABLE();
    for (Seg7& indicator : indicators) {
        indicator.initialize();
    }
    uint32_t lastLedToggle = HAL_GetTick();

    while(1) {
        for (uint32_t digit = 0; digit < 4; ++digit) {
            for (Seg7& indicator : indicators) {
                indicator.blank();
            }
            indicators[digit].display(displayCharacters[digit]);
            HAL_Delay(2);

            if ((HAL_GetTick() - lastLedToggle) >= 500U) {
                HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
                lastLedToggle = HAL_GetTick();
            }
        }
    }
}
