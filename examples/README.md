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
- `Ring_buffer_C/` — приклад кільцевого буфера на C.
- `Ring_buffer_C++/` — приклад кільцевого буфера на C++.
- `Sort_C/` — приклад бульбашкового сортування на C.
- `Sort_C++/` — приклад бульбашкового сортування на C++.
- `ETL_Versions/` — ті ж задачі Ring Buffer і Sort, реалізовані через ETL.

## API довідка по контейнерах

- `README.array.md` — API для `etl::array`.
- `README.vector.md` — API для `etl::vector`.
- `README.string.md` — API для `etl::string`.
- `README.map.md` — API для `etl::map`.

## Вимоги

- Компілятор `g++` з підтримкою C++17.
- ETL у директорії `../lib/etl/include`.

## Збірка (через Makefile)

Усі приклади збираються за допомогою `make` (на Windows/MinGW — `mingw32-make`). Додатковий шлях до ETL можна задати змінною `ETL_INC` (за замовчуванням `../lib/etl/include`).

### Усі приклади (з директорії `examples`)

```bash
cd examples
make          # ETL-приклади + усі підпроєкти (Clock, Ring_buffer_*, Sort_*, ETL_Versions/*)
make clean    # видалити зібрані файли
```

### Один приклад

```bash
cd examples
make etl_vector_example.exe
make etl_map_api_example.exe ETL_INC=/path/to/etl/include
```

### Підпроєкти

```bash
make -C examples/Ring_buffer_C
make -C examples/Ring_buffer_C++
make -C examples/Sort_C
make -C examples/Sort_C++
make -C examples/ETL_Versions/Ring_buffer_ETL
make -C examples/ETL_Versions/Sort_ETL
```

Кожен Makefile має цілі `all` (за замовчуванням) і `clean`. Корінь проєкту також має `Makefile` для `main.cpp` (`make`, `make run`, `make clean`).
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
./examples/Ring_buffer_C/ring_c.exe
./examples/Ring_buffer_C++/ring_cpp.exe
./examples/Sort_C/sort_c.exe
./examples/Sort_C++/sort_cpp.exe
./examples/ETL_Versions/Ring_buffer_ETL/ring_buffer_etl.exe
./examples/ETL_Versions/Sort_ETL/sort_etl.exe
```

## Запуск через VS Code Tasks

У проєкті вже додані задачі:

- `Build C++ with ETL`
- `Build ETL example`
- `Build all ETL examples`
- `Run ETL example`

Відкрити: **Terminal -> Run Task** та вибрати потрібну задачу.
