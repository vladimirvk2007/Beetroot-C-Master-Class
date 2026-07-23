# Ring Buffer (C++)

Цей приклад показує шаблонний кільцевий буфер на C++.

## Файли

- main.cpp — тестова програма
- ring_buffer.h — шаблон класу RingBuffer

## Збірка

```bash
g++ -std=c++17 examples/Ring_buffer_C++/main.cpp -o examples/Ring_buffer_C++/ring_cpp.exe
```

## Запуск

```bash
./examples/Ring_buffer_C++/ring_cpp.exe
```

## Що демонструє

- шаблон класу з фіксованою місткістю
- push/pop
- перевірку full/empty
