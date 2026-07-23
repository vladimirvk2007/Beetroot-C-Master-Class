# Питання 2. Структура програми в Embedded: C vs C++

## Що таке структура програми

Структура програми це поділ коду на файли та модулі з чіткими ролями:

- де оголошення (інтерфейс);
- де реалізація (логіка);
- як модулі підключаються один до одного;
- як усе збирається в один виконуваний файл.

У вбудованих системах правильна структура важлива для:

- читабельності;
- повторного використання;
- швидкої збірки;
- простого тестування.

## Як створюється програма (pipeline збірки)

Незалежно від C чи C++ зазвичай етапи такі:

1. Preprocessing
- Розкриття `#include`, `#define`, умовної компіляції `#if/#ifdef`.

2. Compilation
- Кожен `.c` або `.cpp` компілюється в окремий object-файл (`.o/.obj`).

3. Linking
- Усі object-файли та бібліотеки об'єднуються в `.elf/.exe/.bin`.

4. (Embedded) Post-build
- Конвертація `.elf` у `.hex/.bin`, прошивка на target.

## Типи файлів у C

### `.h` (header)
Містить інтерфейс:

- оголошення функцій;
- `typedef`, `struct`, `enum`;
- `#define`, `extern` змінні.

### `.c` (source)
Містить реалізацію:

- тіла функцій;
- внутрішні `static` функції/змінні модуля.

### Приклад структури (C)

`adc.h`:

```c
#ifndef ADC_H
#define ADC_H

#include <stdint.h>

void adc_init(void);
uint16_t adc_read(void);

#endif
```

`adc.c`:

```c
#include "adc.h"

static uint16_t g_last_value;

void adc_init(void) {
    g_last_value = 0;
}

uint16_t adc_read(void) {
    return g_last_value;
}
```

`main.c`:

```c
#include "adc.h"

int main(void) {
    adc_init();
    (void)adc_read();
    while (1) {}
}
```

## Типи файлів у C++

### `.h` або `.hpp` (header)
Містить інтерфейс:

- оголошення класів;
- шаблони;
- inline/constexpr функції.

### `.cpp` (source)
Містить реалізацію не-шаблонної логіки:

- методи класів;
- функції модуля;
- точка входу `main()`.

### Приклад структури (C++)

`adc.hpp`:

```cpp
#ifndef ADC_HPP
#define ADC_HPP

#include <cstdint>

class Adc {
public:
    void init();
    uint16_t read() const;

private:
    uint16_t last_value_ = 0;
};

#endif
```

`adc.cpp`:

```cpp
#include "adc.hpp"

void Adc::init() {
    last_value_ = 0;
}

uint16_t Adc::read() const {
    return last_value_;
}
```

`main.cpp`:

```cpp
#include "adc.hpp"

int main() {
    Adc adc;
    adc.init();
    (void)adc.read();
    while (true) {}
}
```

## Різниця між C і C++ у структурі

1. Рівень абстракції
- C: модулі на базі функцій і `struct`.
- C++: модулі на базі класів, шаблонів, просторів імен.

2. Інкапсуляція
- C: умовна (через `static` та дисципліну команди).
- C++: вбудована (`private/public/protected`).

3. Повторне використання
- C: через функції/макроси.
- C++: через класи, шаблони, generic-підхід.

4. Header-логіка
- C: зазвичай лише оголошення.
- C++: частина логіки може бути в header (templates, inline).

5. Сумісність
- C++ може викликати C-код через `extern "C"`.
- Це важливо для HAL/driver шарів, написаних на C.

## Практичні правила для embedded проєкту

- Один модуль = одна відповідальність.
- У header лише те, що потрібно зовнішньому коду.
- Внутрішні деталі приховувати в `.c/.cpp`.
- Мінімізувати глобальні змінні.
- Використовувати include guards (`#ifndef/#define/#endif`) або `#pragma once`.
- Для C++ вбудованих систем тримати контроль над винятками/RTTI/heap політикою.

## Рекомендована структура папок

```text
project/
  inc/            # загальні header-файли
  src/            # реалізація
  drivers/        # HAL/BSP/low-level
  app/            # прикладна логіка
  tests/          # тести
  CMakeLists.txt  # або інша система збірки
```

## Висновок

- У C структура простіша та процедурна.
- У C++ структура масштабованіша завдяки класам і шаблонам.
- Для embedded найкраще працює чітка модульність і контроль залежностей незалежно від обраної мови.
