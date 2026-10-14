# Ring Buffer ETL Version

Це ETL-версія прикладу Ring Buffer.

## Файл

- main.cpp

## Ідея

- Буфер побудований на `etl::array<uint8_t, N>`.
- Логіка `head/tail/count` реалізує кільцевий буфер без динамічної пам'яті.

## Збірка

```bash
cd examples/ETL_Versions/Ring_buffer_ETL
make
```

## Запуск

```bash
./ring_buffer_etl.exe
```

## Що демонструє

- push/pop у буфер
- перевірку overflow
- роботу з fixed-capacity контейнером ETL
