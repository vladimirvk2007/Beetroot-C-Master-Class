# Sort ETL Version

Це ETL-версія прикладу сортування.

## Файл

- main.cpp

## Ідея

- Дані зберігаються у `etl::vector<int, N>`.
- Сортування реалізовано через Bubble Sort.
- Без динамічної пам'яті, з фіксованою максимальною місткістю.

## Збірка

```bash
g++ -std=c++17 examples/ETL_Versions/Sort_ETL/main.cpp -I lib/etl/include -o examples/ETL_Versions/Sort_ETL/sort_etl.exe
```

## Запуск

```bash
./examples/ETL_Versions/Sort_ETL/sort_etl.exe
```

## Що демонструє

- сортування даних у ETL-контейнері
- шаблонну функцію `bubble_sort`
- практичний підхід fixed-capacity для embedded
