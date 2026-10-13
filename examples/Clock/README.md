# Годинник (C++)

Навчальний приклад годинника на C++, який працює через абстрактні інтерфейси. Годинник приймає віртуальний клас секундного тактування та віртуальний клас дисплея, тому реальні реалізації можна замінювати без зміни самого годинника.

На дисплей виводиться лише час у форматі `HH:MM`, наприклад `12:34`. Двокрапка блимає раз на секунду.

## Файли

- `clock.h`, `clock.cpp` — клас `Clock`: відлік часу, блимання двокрапки, оновлення дисплея
- `clock_ticker.h` — абстрактний інтерфейс `ClockTicker` (джерело секундних тактів)
- `clock_display.h` — абстрактний інтерфейс `ClockDisplay` (індикатор часу)
- `real_time_ticker.h`, `real_time_ticker.cpp` — `RealTimeTicker`: тікер реального часу на `std::chrono::steady_clock`
- `console_clock_display.h`, `console_clock_display.cpp` — `ConsoleClockDisplay`: вивід у консоль
- `main.cpp` — збирає годинник із тікера та дисплея і запускає головний цикл
- `Makefile` — збірка

## Архітектура

```text
Clock ──► ClockTicker  (інтерфейс) ◄── RealTimeTicker
      └─► ClockDisplay (інтерфейс) ◄── ConsoleClockDisplay
```

`Clock` залежить лише від інтерфейсів:

- `ClockTicker`: `initialize()`, `consumeSecondTick()` — повертає `true` один раз за кожну минулу секунду.
- `ClockDisplay`: `initialize()`, `setTime()`, `setColon()`, `refresh()`, `blank()`.

Методи `Clock`:

- `initialize()` — ініціалізує тікер і дисплей та показує поточний час;
- `setTime(hours, minutes)` — встановлює час (години 0–23, хвилини 0–59), повертає `false` для некоректних значень;
- `update()` — викликається в циклі: опитує тікер, рахує час, перемикає двокрапку.

## Збірка та запуск

З кореня репозиторію (PowerShell):

```powershell
make -C examples\Clock
.\examples\Clock\clock.exe
```

У Git Bash використовуйте прямі риски: `make -C examples/Clock`.

Видалення зібраного файлу:

```powershell
make -C examples\Clock clean
```

Програма працює безперервно, зупинка — `Ctrl+C`. Для Windows (`main.cpp` використовує `Sleep` з `windows.h`). Приклад виводу: `12:33` → `12 33` → `12:33` …

## Власна реалізація

Щоб підключити інший дисплей чи джерело тактів, успадкуйте `ClockDisplay` або `ClockTicker`, реалізуйте їхні методи та передайте об'єкти в конструктор `Clock`.