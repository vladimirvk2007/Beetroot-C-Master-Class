#include "clock.h"
#include "console_clock_display.h"
#include "real_time_ticker.h"

#include <windows.h>

int main()
{
    // Збираємо годинник із реального тікера та консольного дисплея
    RealTimeTicker ticker;
    ConsoleClockDisplay display;
    Clock clock(ticker, display);

    if (!clock.initialize() || !clock.setTime(12, 33))
    {
        return 1;
    }

    // Основний цикл: опитуємо годинник кожні 10 мс
    while (true)
    {
        if (!clock.update())
        {
            return 1;
        }

        Sleep(10);
    }
}
