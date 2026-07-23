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

### Ring/Sort приклади

```bash
gcc -x c examples/Ring_buffer_C/main.cpp examples/Ring_buffer_C/ring_buffer.c -o examples/Ring_buffer_C/ring_c.exe
g++ -std=c++17 examples/Ring_buffer_C++/main.cpp -o examples/Ring_buffer_C++/ring_cpp.exe
gcc -x c examples/Sort_C/main.cpp examples/Sort_C/sort.c -o examples/Sort_C/sort_c.exe
g++ -std=c++17 examples/Sort_C++/main.cpp -o examples/Sort_C++/sort_cpp.exe
```

### ETL версії Ring/Sort

```bash
g++ -std=c++17 examples/ETL_Versions/Ring_buffer_ETL/main.cpp -I lib/etl/include -o examples/ETL_Versions/Ring_buffer_ETL/ring_buffer_etl.exe
g++ -std=c++17 examples/ETL_Versions/Sort_ETL/main.cpp -I lib/etl/include -o examples/ETL_Versions/Sort_ETL/sort_etl.exe
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
