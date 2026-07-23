# Питання 14. Створення класів

## 1. Що таке клас

Клас у C++ це тип, який об'єднує:

- дані (поля);
- поведінку (методи);
- правила доступу до даних.

Клас допомагає інкапсулювати стан і логіку в одному місці.

---

## 2. Мінімальна структура класу

```cpp
class Counter {
public:
    void increment() {
        ++value_;
    }

    int value() const {
        return value_;
    }

private:
    int value_ = 0;
};
```

Складові:

1. `public`
- Те, що доступно зовні.

2. `private`
- Внутрішній стан, недоступний напряму зовні.

3. Методи
- Функції класу.

4. Поля
- Дані класу.

---

## 3. class vs struct

У C++:

- `class`: доступ за замовчуванням `private`.
- `struct`: доступ за замовчуванням `public`.

Для складніших сутностей частіше використовують `class`.

---

## 4. Створення об'єкта

```cpp
Counter c;
c.increment();
int v = c.value();
```

`c` це екземпляр (об'єкт) класу `Counter`.

---

## 5. Конструктори

Конструктор ініціалізує об'єкт під час створення.

```cpp
class Uart {
public:
    Uart(int baudrate) : baudrate_(baudrate) {}

    int baudrate() const { return baudrate_; }

private:
    int baudrate_;
};
```

```cpp
Uart u(115200);
```

---

## 6. Ініціалізація через список ініціалізації

Рекомендовано ініціалізувати поля саме через список:

```cpp
class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}

private:
    int x_;
    int y_;
};
```

Це ефективніше і правильніше, ніж присвоєння в тілі конструктора.

---

## 7. const-методи

Метод з `const` не змінює стан об'єкта.

```cpp
class Sensor {
public:
    int value() const { return value_; }

private:
    int value_ = 0;
};
```

Практика: getter-методи зазвичай роблять `const`.

---

## 8. Інкапсуляція

Ідея:

- поле `private`;
- доступ і зміни лише через методи.

```cpp
class Temperature {
public:
    bool set_celsius(int t) {
        if (t < -40 || t > 125) {
            return false;
        }
        celsius_ = t;
        return true;
    }

    int celsius() const { return celsius_; }

private:
    int celsius_ = 0;
};
```

Плюс: валідація в одному місці.

---

## 9. Розділення на .hpp і .cpp

### Header (оголошення)

```cpp
#ifndef UART_HPP
#define UART_HPP

class Uart {
public:
    explicit Uart(int baudrate);

    void init();
    int baudrate() const;

private:
    int baudrate_;
};

#endif
```

### Source (реалізація)

```cpp
#include "uart.hpp"

Uart::Uart(int baudrate) : baudrate_(baudrate) {}

void Uart::init() {
    // налаштування периферії
}

int Uart::baudrate() const {
    return baudrate_;
}
```

---

## 10. Ключове слово explicit

`explicit` забороняє небажані неявні перетворення для конструктора з одним параметром.

```cpp
class DelayMs {
public:
    explicit DelayMs(int ms) : ms_(ms) {}

private:
    int ms_;
};
```

Без `explicit` компілятор може робити неочевидні конверсії.

---

## 11. Статичні члени класу

### static поле

Спільне для всіх об'єктів класу.

```cpp
class InstanceCounter {
public:
    InstanceCounter() { ++count_; }
    static int count() { return count_; }

private:
    static int count_;
};

int InstanceCounter::count_ = 0;
```

### static метод

Не має `this`, викликається як `ClassName::method()`.

---

## 12. Дружні функції (friend) - коли обережно

`friend` дає доступ до `private`/`protected`.

Використовуйте тільки коли справді потрібно, бо це послаблює інкапсуляцію.

---

## 13. this pointer

У нестатичних методах є неявний `this` (вказівник на поточний об'єкт).

```cpp
class Led {
public:
    Led& on() {
        state_ = true;
        return *this;
    }

private:
    bool state_ = false;
};
```

Повернення `*this` дозволяє chaining.

---

## 14. Деструктор і правило 0/3/5 (коротко)

### Що таке деструктор

Деструктор це спеціальний метод, який викликається автоматично, коли об'єкт знищується.

Синтаксис:

```cpp
~ClassName() {
    // cleanup
}
```

### Для чого потрібен

1. Звільнення ресурсу (файл, буфер, дескриптор, блокування).
2. Безпечне завершення роботи модуля.
3. Реалізація RAII: ресурс захоплюється в конструкторі, звільняється в деструкторі.

### Простий приклад

```cpp
class FileGuard {
public:
    explicit FileGuard(int handle) : handle_(handle) {}

    ~FileGuard() {
        // close_handle(handle_);
    }

private:
    int handle_;
};
```

Якщо об'єкт `FileGuard` виходить з області видимості, деструктор викликається автоматично.

### Коли деструктор можна не писати

Якщо клас не керує сирими ресурсами вручну, часто достатньо деструктора за замовчуванням.

```cpp
class SensorValue {
public:
    SensorValue(int v) : value_(v) {}

private:
    int value_;
};
```

### Правило 0/3/5 дуже коротко

1. Rule of 0: якщо немає ручного керування ресурсом, спеціальні методи (включно з деструктором) краще не писати.
2. Якщо є ручний ресурс, потрібно продумати copy/move/destructor разом.

Для embedded практики зазвичай краще мінімізувати ручний ownership у базових класах.

---

## 15. Типові помилки

1. Публічні поля без потреби.
2. Відсутність `const` у getter-методах.
3. Ініціалізація через присвоєння замість initializer list.
4. Зловживання global state замість об'єктів.
5. Занадто "великий" клас, який робить все підряд.

---

## 16. Практичний стиль для embedded

1. Невеликі класи з однією відповідальністю.
2. Явні межі вхідних значень у методах.
3. Мінімум dynamic allocation у базових модулях.
4. Максимум `const` там, де можливо.
5. Чіткий поділ шарів:
- `hal` (low-level)
- `drivers`
- `app`

---

## 17. Приклад для заняття

```cpp
#include <cstdint>
#include <iostream>

class PwmChannel {
public:
    explicit PwmChannel(uint16_t max_duty) : max_duty_(max_duty) {}

    bool set_duty(uint16_t duty) {
        if (duty > max_duty_) {
            return false;
        }
        duty_ = duty;
        return true;
    }

    uint16_t duty() const {
        return duty_;
    }

    uint16_t max_duty() const {
        return max_duty_;
    }

private:
    uint16_t max_duty_;
    uint16_t duty_ = 0;
};

int main() {
    PwmChannel pwm(1000);

    if (!pwm.set_duty(1200)) {
        std::cout << "Invalid duty\n";
    }

    pwm.set_duty(500);
    std::cout << "Duty=" << pwm.duty() << "/" << pwm.max_duty() << "\n";
    return 0;
}
```

Що показує приклад:

1. Конструктор + `explicit`.
2. Інкапсуляція полів.
3. Валідація в setter-методі.
4. `const`-методи для читання.

---

## 18. Висновок

Класи це фундамент C++-архітектури. Для embedded вони дають контрольований спосіб описати модулі, приховати внутрішній стан, додати перевірки й зробити код читабельнішим. Головне правило: прості класи, чітка відповідальність, мінімум магії.
