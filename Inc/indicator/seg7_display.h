#ifndef INDICATOR_SEG7_DISPLAY_H
#define INDICATOR_SEG7_DISPLAY_H

#include "indicator/seg7.h"

// Порт і піни сегментів.
static GPIO_TypeDef* const SEGMENT_PORT = GPIOA;
static constexpr uint16_t SEGMENT_A_GPIO = GPIO_PIN_5;
static constexpr uint16_t SEGMENT_B_GPIO = GPIO_PIN_4;
static constexpr uint16_t SEGMENT_C_GPIO = GPIO_PIN_3;
static constexpr uint16_t SEGMENT_D_GPIO = GPIO_PIN_2;
static constexpr uint16_t SEGMENT_E_GPIO = GPIO_PIN_1;
static constexpr uint16_t SEGMENT_F_GPIO = GPIO_PIN_0;
static constexpr uint16_t SEGMENT_G_GPIO = GPIO_PIN_6;
static constexpr uint16_t SEGMENT_DP_GPIO = GPIO_PIN_7;

// Піни вибору чотирьох розрядів.
static GPIO_TypeDef* const IDICATOR_A1_PORT = GPIOA;
static constexpr uint16_t IDICATOR_A1 = GPIO_PIN_8;
static GPIO_TypeDef* const IDICATOR_A2_PORT = GPIOA;
static constexpr uint16_t IDICATOR_A2 = GPIO_PIN_9;
static GPIO_TypeDef* const IDICATOR_A3_PORT = GPIOA;
static constexpr uint16_t IDICATOR_A3 = GPIO_PIN_10;
static GPIO_TypeDef* const IDICATOR_A4_PORT = GPIOB;
static constexpr uint16_t IDICATOR_A4 = GPIO_PIN_3;

struct Seg7DigitConfig
{
    GPIO_TypeDef* port;
    uint16_t pin;
    bool rotated180;
};

struct Seg7DisplayConfig
{
    GPIO_TypeDef* segmentsPort;
    SevenSegmentPins segmentPins;
    Seg7DigitConfig digits[4];
};

// Типове підключення чотиризрядного дисплея до плати.
static const Seg7DisplayConfig SEG7_DISPLAY_DEFAULT_CONFIG = {
    SEGMENT_PORT,
    {SEGMENT_A_GPIO, SEGMENT_B_GPIO, SEGMENT_C_GPIO, SEGMENT_D_GPIO,
     SEGMENT_E_GPIO, SEGMENT_F_GPIO, SEGMENT_G_GPIO, SEGMENT_DP_GPIO},
    {
        {IDICATOR_A1_PORT, IDICATOR_A1, false},
        {IDICATOR_A2_PORT, IDICATOR_A2, false},
        {IDICATOR_A3_PORT, IDICATOR_A3, true},
        {IDICATOR_A4_PORT, IDICATOR_A4, false},
    },
};

// Об'єднує чотири індикатори для мультиплексного виведення символів.
class Seg7Display
{
public:
    explicit Seg7Display(
        const Seg7DisplayConfig& config = SEG7_DISPLAY_DEFAULT_CONFIG);

    // Ініціалізує всі чотири індикатори.
    void initialize();
    // Зберігає рядок рівно з чотирьох символів.
    bool setText(const char* text);
    // Оновлює черговий розряд; повертає false для непідтримуваного символу.
    bool refresh();
    // Вимикає всі розряди.
    void blank();

private:
    Seg7 first_;
    Seg7 second_;
    Seg7 third_;
    Seg7 fourth_;
    Seg7* indicators_[4];
    char text_[4];
    uint8_t activeDigit_;
};

#endif // INDICATOR_SEG7_DISPLAY_H
