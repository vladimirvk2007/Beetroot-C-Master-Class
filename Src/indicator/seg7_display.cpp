#include "indicator/seg7_display.h"

Seg7Display::Seg7Display(const Seg7DisplayConfig& config)
    : first_(config.segmentsPort, config.segmentPins,
             config.digits[0].port, config.digits[0].pin,
             config.digits[0].rotated180),
      second_(config.segmentsPort, config.segmentPins,
              config.digits[1].port, config.digits[1].pin,
              config.digits[1].rotated180),
      third_(config.segmentsPort, config.segmentPins,
             config.digits[2].port, config.digits[2].pin,
             config.digits[2].rotated180),
      fourth_(config.segmentsPort, config.segmentPins,
              config.digits[3].port, config.digits[3].pin,
              config.digits[3].rotated180),
      indicators_{&first_, &second_, &third_, &fourth_},
      text_{' ', ' ', ' ', ' '},
      decimalPoints_(0),
      activeDigit_(0)
{
}

// Ініціалізує порти та піни всіх чотирьох індикаторів.
void Seg7Display::initialize()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    for (Seg7* indicator : indicators_) {
        indicator->initialize();
    }
}

// Приймає лише рядок рівно з чотирьох символів.
bool Seg7Display::setText(const char* text)
{
    if (text == nullptr || text[0] == '\0' || text[1] == '\0' ||
        text[2] == '\0' || text[3] == '\0' || text[4] != '\0') {
        return false;
    }

    for (uint8_t i = 0; i < 4; ++i) {
        text_[i] = text[i];
    }
    return true;
}

// Номер розряду задається в звичному діапазоні 1–4.
bool Seg7Display::setDecimalPoint(uint8_t digit, bool enabled)
{
    if (digit < 1U || digit > 4U) {
        return false;
    }

    const uint8_t mask = 1U << (digit - 1U);
    if (enabled) {
        decimalPoints_ |= mask;
    } else {
        decimalPoints_ &= static_cast<uint8_t>(~mask);
    }
    return true;
}

// Дві сусідні крапки утворюють двокрапку між розрядами 2 і 3.
void Seg7Display::setColon(bool enabled)
{
    setDecimalPoint(2, enabled);
    setDecimalPoint(3, enabled);
}

// Виводить символ на поточний розряд і переходить до наступного.
bool Seg7Display::refresh()
{
    blank();
    const bool decimalPoint =
        (decimalPoints_ & (1U << activeDigit_)) != 0;
    const bool displayed =
        indicators_[activeDigit_]->display(text_[activeDigit_], decimalPoint);
    activeDigit_ = (activeDigit_ + 1U) % 4U;
    return displayed;
}

// Вимикає всі розряди перед оновленням дисплея.
void Seg7Display::blank()
{
    for (Seg7* indicator : indicators_) {
        indicator->blank();
    }
}
