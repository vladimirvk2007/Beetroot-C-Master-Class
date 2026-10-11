#ifndef INDICATOR_SEG7_H
#define INDICATOR_SEG7_H

#include "main.h"

// GPIO-маски сегментів одного індикатора.
struct SevenSegmentPins
{
    uint16_t a;
    uint16_t b;
    uint16_t c;
    uint16_t d;
    uint16_t e;
    uint16_t f;
    uint16_t g;
    uint16_t dp;
};

// Керує одним семисегментним індикатором зі спільним портом сегментів.
class Seg7
{
public:
    // rotated180 вмикає програмний поворот символів на 180 градусів.
    Seg7(GPIO_TypeDef* segmentsPort,
         const SevenSegmentPins& segmentPins,
         GPIO_TypeDef* digitPort,
         uint16_t digitPin,
         bool rotated180 = false);

    // Налаштовує піни сегментів і вибору розряду як виходи.
    void initialize();
    // Показує цифру або підтримувану літеру; false для невідомого символу.
    bool display(char symbol, bool decimalPoint = false);
    // Вимикає цей розряд.
    void blank();

private:
    // Формує маски GPIO для всіх сегментів або вибраних сегментів.
    uint16_t allSegmentsMask() const;
    uint16_t gpioMaskFor(uint8_t segments) const;

    GPIO_TypeDef* segmentsPort_;
    SevenSegmentPins segmentPins_;
    GPIO_TypeDef* digitPort_;
    uint16_t digitPin_;
    bool rotated180_;
};

#endif // INDICATOR_SEG7_H
