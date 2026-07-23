# ETL Vector API

Цей файл описує базовий API контейнера `etl::vector`.

Пов'язаний приклад: `etl_vector_example.cpp`.

## Коротко

- Контейнер з фіксованою максимальною місткістю.
- Поточний розмір змінюється в межах `capacity`.
- Без динамічних алокацій у heap.

## Основний API

### Доступ до елементів

- `operator[](index)`
- `at(index)`
- `front()`
- `back()`
- `data()`

### Ітератори

- `begin()`, `end()`
- `cbegin()`, `cend()`
- `rbegin()`, `rend()`

### Ємність

- `size()`
- `max_size()`
- `capacity()`
- `empty()`
- `full()`

### Модифікація

- `push_back(value)`
- `emplace_back(...)`
- `pop_back()`
- `insert(...)`
- `erase(...)`
- `clear()`
- `resize(n)`
- `assign(...)`

## Нотатки

- Перевищення місткості призведе до помилки ETL (assert/exception залежно від конфігурації).
