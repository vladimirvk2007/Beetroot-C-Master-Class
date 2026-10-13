#include "clock.h"
#include "console_clock_display.h"
#include "real_time_ticker.h"

#include <windows.h>

int main()
{
    RealTimeTicker ticker;
    ConsoleClockDisplay display;
    Clock clock(ticker, display);

    if (!clock.initialize() || !clock.setTime(12, 33))
    {
        return 1;
    }

    while (true)
    {
        if (!clock.update())
        {
            return 1;
        }

        Sleep(10);
    }
}
