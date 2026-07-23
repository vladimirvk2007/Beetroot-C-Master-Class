# ETL Map API

Цей файл описує базовий API контейнера `etl::map`.

Пов'язаний приклад: `etl_map_example.cpp`.

## Коротко

- Асоціативний контейнер key-value з фіксованою максимальною кількістю елементів.
- Ключі відсортовані.
- Без heap-алокацій.

## Основний API

### Доступ

- `operator[](key)`
- `at(key)`
- `find(key)`
- `count(key)`

### Ітератори

- `begin()`, `end()`
- `cbegin()`, `cend()`
- `rbegin()`, `rend()`

### Ємність

- `size()`
- `max_size()`
- `empty()`
- `full()`

### Модифікація

- `insert(value)`
- `emplace(...)`
- `erase(key)`
- `erase(iterator)`
- `clear()`
- `swap(other)`

## Нотатки

- У `map` ключі унікальні.
- Для перевірки наявності ключа використовуйте `find` або `count`.
