# Питання 13. Простори імен (namespace)

## 1. Що таке namespace

`namespace` у C++ це механізм логічного групування імен:

- функцій;
- класів;
- змінних;
- констант;
- типів.

Головна мета: уникнути конфліктів імен у великих проєктах та бібліотеках.

---

## 2. Чому це важливо

Без `namespace` два модулі можуть мати однакову функцію `init()`, `read()`, `print()` і конфліктувати під час компіляції/лінкування.

`namespace` дозволяє мати:

- `uart::init()`
- `spi::init()`

і це різні сутності.

---

## 3. Базовий синтаксис

```cpp
namespace sensors {
    int read_temperature() {
        return 25;
    }
}

int t = sensors::read_temperature();
```

`::` це оператор області видимості (scope resolution operator).

---

## 4. Namespace у кількох блоках

Один і той самий простір імен можна "дописувати":

```cpp
namespace drivers {
    void init_uart();
}

namespace drivers {
    void init_spi();
}
```

Це зручно для розбиття коду по файлах.

---

## 5. Вкладені простори імен

```cpp
namespace company {
namespace board {
namespace uart {
    void init();
}
}
}
```

Сучасний запис (C++17):

```cpp
namespace company::board::uart {
    void init();
}
```

---

## 6. Псевдоніми namespace

Якщо шлях довгий, можна створити alias:

```cpp
namespace hw = company::board::uart;

hw::init();
```

---

## 7. using для namespace

### using declaration

```cpp
using drivers::init_uart;
init_uart();
```

Імпортує одне ім'я.

### using directive

```cpp
using namespace drivers;
```

Імпортує всі імена з простору.

### Рекомендація

- У заголовках (`.h/.hpp`) уникайте `using namespace ...`.
- У `.cpp` теж використовуйте обережно, краще явний `drivers::name`.

---

## 8. Анонімний namespace

```cpp
namespace {
    int local_state = 0;
    void helper() {}
}
```

Що це дає:

- сутності видимі тільки в поточному `.cpp` файлі;
- аналог internal linkage для C++.

Для C аналог часто роблять через `static` на рівні файлу.

---

## 9. Namespace і global scope

Якщо локально є ім'я з таким самим словом, можна звернутися до глобального через `::`.

```cpp
int value = 1;

namespace app {
    int value = 2;

    int get_global() {
        return ::value;
    }
}
```

---

## 10. Namespace і класи

Клас усередині namespace:

```cpp
namespace comm {
    class Uart {
    public:
        void init();
    };
}

comm::Uart uart;
```

Реалізація методу в `.cpp`:

```cpp
void comm::Uart::init() {
    // ...
}
```

---

## 11. Namespace у header/source

### Header (`uart.hpp`)

```cpp
#ifndef UART_HPP
#define UART_HPP

namespace hal {
    void uart_init();
}

#endif
```

### Source (`uart.cpp`)

```cpp
#include "uart.hpp"

namespace hal {
    void uart_init() {
        // реалізація
    }
}
```

Важливо, щоб оголошення і реалізація були в одному namespace.

---

## 12. Типові помилки

1. Оголосили функцію в одному namespace, реалізували в іншому.
2. Використали `using namespace ...` у header і "забруднили" глобальну область.
3. Забули префікс namespace і отримали "not found" або конфлікт імен.
4. Зловживають дуже довгими вкладеними namespace без alias.

---

## 13. Практичні рекомендації для embedded

1. Розділяйте шари по namespace, наприклад:
- `hal` (hardware abstraction)
- `drivers`
- `app`
- `utils`

2. Для кожного модуля тримайте однаковий namespace у `.hpp` і `.cpp`.

3. Уникайте `using namespace` у публічних header-файлах.

4. Використовуйте анонімний namespace в `.cpp` для внутрішніх helper-функцій.

5. Для великих ієрархій створюйте namespace-alias у локальному `.cpp`.

---

## 14. Міні-приклад структури

```cpp
namespace hal {
    void gpio_write(int pin, bool value);
}

namespace drivers {
    void led_on();
}

namespace app {
    void run();
}
```

- `hal` відповідає за low-level.
- `drivers` будується поверх `hal`.
- `app` використовує `drivers`.

---

## 15. Порівняння з C

У C немає `namespace` як мовного механізму.

Типова практика в C:

- префікси в іменах (`uart_init`, `spi_init`, `app_run`);
- `static` для приховування внутрішніх функцій на рівні файлу.

У C++ `namespace` робить це системніше і безпечніше.

---

## 16. Висновок

`namespace` це базовий інструмент організації C++ коду. Для embedded він особливо корисний, бо допомагає тримати архітектуру чистою, уникати конфліктів імен та відділяти шари системи (`hal`, `drivers`, `app`).
