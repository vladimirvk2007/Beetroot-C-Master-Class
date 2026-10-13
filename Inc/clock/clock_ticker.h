#ifndef CLOCK_TICKER_H
#define CLOCK_TICKER_H

class ClockTicker
{
public:
    virtual ~ClockTicker() = default;

    virtual void initialize() = 0;

    // Returns true once for each elapsed second.
    virtual bool consumeSecondTick() = 0;
};

#endif // CLOCK_TICKER_H
