# ETL String API

Цей файл описує базовий API контейнера `etl::string`.

Пов'язаний приклад: `etl_string_example.cpp`.

## Коротко

- Рядок з фіксованою максимальною довжиною.
- Інтерфейс близький до `std::string`.
- Без heap-алокацій.

## Основний API

### Доступ

- `operator[](index)`
- `at(index)`
- `front()`
- `back()`
- `c_str()`
- `data()`

### Ємність

- `size()`
- `max_size()`
- `capacity()`
- `empty()`
- `full()`

### Модифікація

- `append(...)`
- `operator+=(...)`
- `push_back(ch)`
- `pop_back()`
- `insert(...)`
- `erase(...)`
- `clear()`
- `resize(n)`

### Пошук і порівняння

- `find(...)`
- `rfind(...)`
- `compare(...)`

## Нотатки

- При додаванні символів стежте за максимальною місткістю.
