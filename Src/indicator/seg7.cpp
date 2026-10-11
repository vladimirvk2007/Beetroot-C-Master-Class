#include "indicator/seg7.h"

namespace
{
// Внутрішні прапорці сегментів для формування символів.
enum Segment
{
    SegmentA = 1U << 0,
    SegmentB = 1U << 1,
    SegmentC = 1U << 2,
    SegmentD = 1U << 3,
    SegmentE = 1U << 4,
    SegmentF = 1U << 5,
    SegmentG = 1U << 6,
    SegmentDp = 1U << 7
};

// Шаблони цифр 0–9 у порядку індексів масиву.
const uint8_t digitPatterns[] = {
    SegmentA | SegmentB | SegmentC | SegmentD | SegmentE | SegmentF,
    SegmentB | SegmentC,
    SegmentA | SegmentB | SegmentD | SegmentE | SegmentG,
    SegmentA | SegmentB | SegmentC | SegmentD | SegmentG,
    SegmentB | SegmentC | SegmentF | SegmentG,
    SegmentA | SegmentC | SegmentD | SegmentF | SegmentG,
    SegmentA | SegmentC | SegmentD | SegmentE | SegmentF | SegmentG,
    SegmentA | SegmentB | SegmentC,
    SegmentA | SegmentB | SegmentC | SegmentD | SegmentE | SegmentF | SegmentG,
    SegmentA | SegmentB | SegmentC | SegmentD | SegmentF | SegmentG,
};

uint8_t rotateSegments180(uint8_t segments)
{
    uint8_t rotated = segments & (SegmentG | SegmentDp);

    if (segments & SegmentA) rotated |= SegmentD;
    if (segments & SegmentB) rotated |= SegmentE;
    if (segments & SegmentC) rotated |= SegmentF;
    if (segments & SegmentD) rotated |= SegmentA;
    if (segments & SegmentE) rotated |= SegmentB;
    if (segments & SegmentF) rotated |= SegmentC;

    return rotated;
}

// Перетворює підтримуваний символ на маску сегментів.
bool segmentsFor(char symbol, uint8_t& segments)
{
    if (symbol >= '0' && symbol <= '9') {
        segments = digitPatterns[symbol - '0'];
        return true;
    }

    switch (symbol)
    {
    case 'A':
    case 'a':
        segments = SegmentA | SegmentB | SegmentC | SegmentE | SegmentF | SegmentG;
        break;
    case 'B':
    case 'b':
        segments = SegmentC | SegmentD | SegmentE | SegmentF | SegmentG;
        break;
    case 'C':
    case 'c':
        segments = symbol == 'c'
            ? SegmentD | SegmentE | SegmentG
            : SegmentA | SegmentD | SegmentE | SegmentF;
        break;
    case 'D':
    case 'd':
        segments = SegmentB | SegmentC | SegmentD | SegmentE | SegmentG;
        break;
    case 'E':
    case 'e':
        segments = SegmentA | SegmentD | SegmentE | SegmentF | SegmentG;
        break;
    case 'F':
    case 'f':
        segments = SegmentA | SegmentE | SegmentF | SegmentG;
        break;
    case 'H':
    case 'h':
        segments = symbol == 'h'
            ? SegmentC | SegmentE | SegmentF | SegmentG
            : SegmentB | SegmentC | SegmentE | SegmentF | SegmentG;
        break;
    case 'L':
    case 'l':
        segments = SegmentD | SegmentE | SegmentF;
        break;
    case 'P':
    case 'p':
        segments = SegmentA | SegmentB | SegmentE | SegmentF | SegmentG;
        break;
    case 'U':
    case 'u':
        segments = SegmentB | SegmentC | SegmentD | SegmentE | SegmentF;
        break;
    default:
        return false;
    }

    return true;
}
}

Seg7::Seg7(GPIO_TypeDef* segmentsPort,
           const SevenSegmentPins& segmentPins,
           GPIO_TypeDef* digitPort,
           uint16_t digitPin,
           bool rotated180)
    : segmentsPort_(segmentsPort),
      segmentPins_(segmentPins),
      digitPort_(digitPort),
      digitPin_(digitPin),
      rotated180_(rotated180)
{
}

void Seg7::initialize()
{
    // Сегменти та вибір розряду активні низьким рівнем.
    HAL_GPIO_WritePin(segmentsPort_, allSegmentsMask(), GPIO_PIN_SET);
    HAL_GPIO_WritePin(digitPort_, digitPin_, GPIO_PIN_SET);

    GPIO_InitTypeDef gpioInit = {};
    gpioInit.Mode = GPIO_MODE_OUTPUT_PP;
    gpioInit.Pull = GPIO_NOPULL;
    gpioInit.Speed = GPIO_SPEED_FREQ_LOW;
    gpioInit.Pin = allSegmentsMask();
    HAL_GPIO_Init(segmentsPort_, &gpioInit);

    gpioInit.Pin = digitPin_;
    HAL_GPIO_Init(digitPort_, &gpioInit);
}

bool Seg7::display(char symbol, bool decimalPoint)
{
    // Спершу вимикаємо розряд, щоб не показати некоректний символ.
    blank();
    uint8_t segments;
    if (!segmentsFor(symbol, segments)) {
        return false;
    }

    if (rotated180_) {
        segments = rotateSegments180(segments);
    }
    if (decimalPoint) {
        segments |= SegmentDp;
    }

    HAL_GPIO_WritePin(segmentsPort_, allSegmentsMask(), GPIO_PIN_SET);
    HAL_GPIO_WritePin(segmentsPort_, gpioMaskFor(segments), GPIO_PIN_RESET);
    HAL_GPIO_WritePin(digitPort_, digitPin_, GPIO_PIN_RESET);
    return true;
}

void Seg7::blank()
{
    // Високий рівень вимикає індикатор.
    HAL_GPIO_WritePin(digitPort_, digitPin_, GPIO_PIN_SET);
}

uint16_t Seg7::allSegmentsMask() const
{
    return segmentPins_.a | segmentPins_.b | segmentPins_.c | segmentPins_.d |
           segmentPins_.e | segmentPins_.f | segmentPins_.g | segmentPins_.dp;
}

uint16_t Seg7::gpioMaskFor(uint8_t segments) const
{
    // Перетворює логічні прапорці A–DP на GPIO-маску, задану користувачем.
    uint16_t mask = 0;
    if (segments & SegmentA) mask |= segmentPins_.a;
    if (segments & SegmentB) mask |= segmentPins_.b;
    if (segments & SegmentC) mask |= segmentPins_.c;
    if (segments & SegmentD) mask |= segmentPins_.d;
    if (segments & SegmentE) mask |= segmentPins_.e;
    if (segments & SegmentF) mask |= segmentPins_.f;
    if (segments & SegmentG) mask |= segmentPins_.g;
    if (segments & SegmentDp) mask |= segmentPins_.dp;
    return mask;
}
