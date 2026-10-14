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
cd examples/ETL_Versions/Sort_ETL
make
```

## Запуск

```bash
./sort_etl.exe
```

## Що демонструє

- сортування даних у ETL-контейнері
- шаблонну функцію `bubble_sort`
- практичний підхід fixed-capacity для embedded
