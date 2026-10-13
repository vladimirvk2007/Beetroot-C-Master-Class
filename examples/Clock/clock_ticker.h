#ifndef CLOCK_TICKER_H
#define CLOCK_TICKER_H

// Абстрактне джерело секундного тактування для годинника.
class ClockTicker
{
public:
    virtual ~ClockTicker() = default;

    // Ініціалізація джерела тактів
    virtual void initialize() = 0;

    // Повертає true один раз за кожну минулу секунду
    virtual bool consumeSecondTick() = 0;
};

#endif // CLOCK_TICKER_H
