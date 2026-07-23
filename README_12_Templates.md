# Питання 12. Шаблони (Templates)

## 1. Що таке шаблони

Шаблони в C++ це механізм узагальненого програмування (generic programming), який дозволяє писати код один раз для різних типів.

Ідея проста:

- замість конкретного типу (`int`, `float`, `MyType`) ви пишете параметр типу (`T`);
- компілятор підставляє конкретний тип і генерує потрібну версію коду.

---

## 2. Чому це важливо в embedded

1. Менше дублювання
- Не треба писати однакові функції для `uint8_t`, `uint16_t`, `uint32_t`.

2. Type safety
- На відміну від макросів, шаблони перевіряються компілятором за типами.

3. Zero-cost абстракції
- За правильного дизайну шаблони не додають runtime-overhead.

4. Compile-time конфігурація
- Можна задавати розмір буфера, політику обробки, параметри алгоритму на етапі компіляції.

---

## 3. Шаблон функції

### Базовий приклад

```cpp
template <typename T>
T max_value(T a, T b) {
    return (a > b) ? a : b;
}
```

Використання:

```cpp
int a = max_value(3, 7);
float b = max_value(2.5f, 1.0f);
```

Компілятор створить окремі версії для `int` і `float`.

---

## 4. Шаблон класу

### Базовий приклад

```cpp
template <typename T>
class Box {
public:
    explicit Box(T value) : value_(value) {}
    T get() const { return value_; }

private:
    T value_;
};
```

Використання:

```cpp
Box<int> bi(10);
Box<float> bf(3.14f);
```

---

## 5. Кілька параметрів шаблону

```cpp
template <typename T, typename U>
auto add(T a, U b) {
    return a + b;
}
```

---

## 6. Нетипові параметри шаблону (non-type template params)

Дуже корисні для embedded.

```cpp
template <size_t N>
constexpr size_t bytes_for_u32_words() {
    return N * sizeof(uint32_t);
}
```

Використання:

```cpp
constexpr size_t rx_words = 16;
constexpr size_t rx_bytes = bytes_for_u32_words<rx_words>();
```

Тут `N` це compile-time параметр: значення обчислюється під час компіляції.

---

## 7. typename і class у шаблонах

У списку параметрів шаблону `typename` і `class` майже еквівалентні:

```cpp
template <typename T>
// те саме, що template <class T>
```

Стильово часто використовують `typename` для читабельності.

---

## 8. Спеціалізація шаблонів

### Повна спеціалізація

```cpp
template <typename T>
struct TypeName {
    static const char* get() { return "unknown"; }
};

template <>
struct TypeName<int> {
    static const char* get() { return "int"; }
};
```

### Часткова спеціалізація (для класів)

```cpp
template <typename T>
struct PointerInfo {
    static const char* kind() { return "not pointer"; }
};

template <typename T>
struct PointerInfo<T*> {
    static const char* kind() { return "pointer"; }
};
```

---

## 9. Інстанціювання і вплив на розмір коду

Для кожної комбінації параметрів компілятор генерує окрему версію (інстанс):

- `foo<int>`
- `foo<uint32_t>`
- `foo<float>`

Це зручно, але може збільшувати розмір бінарника (code bloat).

Практики зменшення:

1. Не інстанціюйте шаблон на зайвих типах.
2. Виносьте важку логіку у спільні нешаблонні функції, коли можливо.
3. Використовуйте оптимізації компілятора (`-Os`, `-O2`) і аналіз map-файлу.

---

## 10. Де тримати реалізацію шаблонів

На відміну від звичайних `.cpp`, шаблонний код зазвичай має бути видимий у місці використання.

Тому частіше:

- оголошення і реалізація шаблонів у `.h/.hpp`;
- або розділення через `.tpp/.ipp`, які підключаються в header.

---

## 11. Типові помилки

1. Реалізація шаблону лише в `.cpp`
- У місці використання компілятор не бачить визначення.

2. Дуже складні повідомлення помилок
- Часто причина вище у першій значущій помилці типу.

3. Надмірне ускладнення
- Шаблон там, де достатньо простої функції.

4. Змішування несумісних типів без контролю
- Потрібні `static_assert` або обмеження шаблону.

---

## 12. static_assert у шаблонах

`static_assert` допомагає робити помилки зрозумілішими.

```cpp
#include <type_traits>

template <typename T>
T increment(T v) {
    static_assert(std::is_integral<T>::value, "increment requires integral type");
    return v + 1;
}
```

---

## 13. Шаблони і constexpr

Часто працюють разом.

```cpp
template <size_t N>
constexpr size_t bytes_for_words() {
    return N * sizeof(uint32_t);
}

static_assert(bytes_for_words<4>() == 16, "Size mismatch");
```

Це дає compile-time перевірки без runtime витрат.

---

## 14. Практичні embedded-патерни

1. Фіксовані буфери
- `template <typename T, size_t N>`.

2. Політики (policy-based design)
- один алгоритм, різна політика доступу/логування/перевірки.

3. Драйвери за параметрами периферії
- compile-time конфігурація порту/піна/таймера.

4. Контейнери ETL
- активно використовують шаблони (тип + місткість + політики).

---

## 15. Приклад для заняття

```cpp
#include <cstddef>
#include <cstdint>
#include <iostream>

template <typename T, std::size_t N>
class RingLikeBuffer {
public:
    bool push(const T& v) {
        if (count_ == N) {
            return false;
        }
        data_[(head_ + count_) % N] = v;
        ++count_;
        return true;
    }

    bool pop(T& out) {
        if (count_ == 0) {
            return false;
        }
        out = data_[head_];
        head_ = (head_ + 1) % N;
        --count_;
        return true;
    }

    std::size_t size() const { return count_; }
    constexpr std::size_t capacity() const { return N; }

private:
    T data_[N]{};
    std::size_t head_ = 0;
    std::size_t count_ = 0;
};

int main() {
    RingLikeBuffer<uint8_t, 4> q;
    q.push(10);
    q.push(20);

    uint8_t v = 0;
    if (q.pop(v)) {
        std::cout << static_cast<int>(v) << "\n";
    }

    std::cout << "size=" << q.size() << ", cap=" << q.capacity() << "\n";
    return 0;
}
```

Що показує приклад:

1. Шаблон класу з типом `T`.
2. Нетиповий параметр `N` для compile-time місткості.
3. Без dynamic allocation.
4. Патерн, близький до embedded-практики.

---

## 16. Коли шаблони не потрібні

1. Коли є лише один фіксований тип і це не зміниться.
2. Коли шаблон ускладнює читання без реальної користі.
3. Коли команда ще не готова підтримувати складний template-код.

---

## 17. Висновок

Шаблони це один з найсильніших інструментів C++ для embedded:

- прибирають дублювання;
- зберігають type safety;
- дають compile-time конфігурацію;
- дозволяють zero-cost абстракції.

Водночас важливо тримати баланс: простий дизайн, зрозумілі помилки, контроль розміру коду і практичність для конкретного проєкту.
