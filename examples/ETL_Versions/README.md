# ETL Versions

Ця директорія містить ті самі навчальні задачі (Ring Buffer і Sort), але реалізовані з використанням ETL.

## Структура

- Ring_buffer_ETL/main.cpp
- Sort_ETL/main.cpp

## Збірка

```bash
g++ -std=c++17 examples/ETL_Versions/Ring_buffer_ETL/main.cpp -I lib/etl/include -o examples/ETL_Versions/Ring_buffer_ETL/ring_buffer_etl.exe

g++ -std=c++17 examples/ETL_Versions/Sort_ETL/main.cpp -I lib/etl/include -o examples/ETL_Versions/Sort_ETL/sort_etl.exe
```

## Запуск

```bash
./examples/ETL_Versions/Ring_buffer_ETL/ring_buffer_etl.exe
./examples/ETL_Versions/Sort_ETL/sort_etl.exe
```
