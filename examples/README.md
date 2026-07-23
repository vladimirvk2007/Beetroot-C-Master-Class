# Приклади ETL у цьому проєкті

У цій директорії зібрані мінімальні приклади використання бібліотеки **Embedded Template Library (ETL)**.

## Вміст

- `etl_vector_example.cpp` — приклад роботи з `etl::vector` фіксованої місткості.
- `etl_array_example.cpp` — приклад роботи з `etl::array` та обчисленням суми елементів.
- `etl_string_example.cpp` — приклад роботи з `etl::string` без динамічної пам'яті.
- `etl_map_example.cpp` — приклад роботи з `etl::map` (вставка та ітерація по значеннях).
- `etl_vector_api_example.cpp` — розширений демо-приклад API для `etl::vector`.
- `etl_array_api_example.cpp` — розширений демо-приклад API для `etl::array`.
- `etl_string_api_example.cpp` — розширений демо-приклад API для `etl::string`.
- `etl_map_api_example.cpp` — розширений демо-приклад API для `etl::map`.

## API довідка по контейнерах

- `README.array.md` — API для `etl::array`.
- `README.vector.md` — API для `etl::vector`.
- `README.string.md` — API для `etl::string`.
- `README.map.md` — API для `etl::map`.

## Вимоги

- Компілятор `g++` з підтримкою C++17.
- ETL у директорії `../lib/etl/include`.

## Швидка збірка (з кореня проєкту)

### Один приклад (vector)

```bash
g++ -std=c++17 examples/etl_vector_example.cpp -I lib/etl/include -o examples/etl_vector_example.exe
```

### Усі приклади

```bash
g++ -std=c++17 examples/etl_vector_example.cpp -I lib/etl/include -o examples/etl_vector_example.exe && \
g++ -std=c++17 examples/etl_array_example.cpp -I lib/etl/include -o examples/etl_array_example.exe && \
g++ -std=c++17 examples/etl_string_example.cpp -I lib/etl/include -o examples/etl_string_example.exe && \
g++ -std=c++17 examples/etl_map_example.cpp -I lib/etl/include -o examples/etl_map_example.exe
```

### API демо-приклади

```bash
g++ -std=c++17 examples/etl_vector_api_example.cpp -I lib/etl/include -o examples/etl_vector_api_example.exe && \
g++ -std=c++17 examples/etl_array_api_example.cpp -I lib/etl/include -o examples/etl_array_api_example.exe && \
g++ -std=c++17 examples/etl_string_api_example.cpp -I lib/etl/include -o examples/etl_string_api_example.exe && \
g++ -std=c++17 examples/etl_map_api_example.cpp -I lib/etl/include -o examples/etl_map_api_example.exe
```

## Запуск прикладів

```bash
./examples/etl_vector_example.exe
./examples/etl_array_example.exe
./examples/etl_string_example.exe
./examples/etl_map_example.exe
./examples/etl_vector_api_example.exe
./examples/etl_array_api_example.exe
./examples/etl_string_api_example.exe
./examples/etl_map_api_example.exe
```

## Запуск через VS Code Tasks

У проєкті вже додані задачі:

- `Build C++ with ETL`
- `Build ETL example`
- `Build all ETL examples`
- `Run ETL example`

Відкрити: **Terminal -> Run Task** та вибрати потрібну задачу.
