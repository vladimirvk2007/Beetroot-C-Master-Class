#include <etl/vector.h>
#include <cstddef>
#include <iostream>

template <typename T, std::size_t Capacity>
void bubble_sort(etl::vector<T, Capacity>& data) {
    if (data.size() <= 1) {
        return;
    }

    for (std::size_t i = 0; i + 1 < data.size(); ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j + 1 < data.size() - i; ++j) {
            if (data[j] > data[j + 1]) {
                T tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    etl::vector<int, 16> values;
    values.push_back(10);
    values.push_back(6);
    values.push_back(-1);
    values.push_back(9);
    values.push_back(77);

    bubble_sort(values);

    for (std::size_t i = 0; i < values.size(); ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
