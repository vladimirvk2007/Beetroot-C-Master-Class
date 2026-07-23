# Ring Buffer (C)

Цей приклад показує базову реалізацію кільцевого буфера на C.

## Файли

- main.cpp — тестова програма
- ring_buffer.h — API буфера
- ring_buffer.c — реалізація

## Збірка

```bash
gcc -x c examples/Ring_buffer_C/main.cpp examples/Ring_buffer_C/ring_buffer.c -o examples/Ring_buffer_C/ring_c.exe
```

## Запуск

```bash
./examples/Ring_buffer_C/ring_c.exe
```

## Що демонструє

- ініціалізацію буфера
- перевірку переповнення
- додавання елементів (push)
- роботу індексів head/tail
