# Ring Buffer ETL Version

Це ETL-версія прикладу Ring Buffer.

## Файл

- main.cpp

## Ідея

- Буфер побудований на `etl::array<uint8_t, N>`.
- Логіка `head/tail/count` реалізує кільцевий буфер без динамічної пам'яті.

## Збірка

```bash
g++ -std=c++17 examples/ETL_Versions/Ring_buffer_ETL/main.cpp -I lib/etl/include -o examples/ETL_Versions/Ring_buffer_ETL/ring_buffer_etl.exe
```

## Запуск

```bash
./examples/ETL_Versions/Ring_buffer_ETL/ring_buffer_etl.exe
```

## Що демонструє

- push/pop у буфер
- перевірку overflow
- роботу з fixed-capacity контейнером ETL
