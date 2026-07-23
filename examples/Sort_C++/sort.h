#ifndef SORT_HPP
#define SORT_HPP

#include <utility> // Для std::swap
#include <cstddef> // Для std::size_t

template <typename T, std::size_t N>

void bubble_sort(T (&arr)[N]) {
    if (N <= 1) {
        return;
    }

    bool swapped = false;
    for (std::size_t i = 0; i < N - 1; ++i) {
        swapped = false;
        for (std::size_t j = 0; j < N - i - 1; ++j) {
            auto& current = arr[j];
            auto& next = arr[j + 1];
            
            if (current > next) {
                std::swap(current, next);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

#endif // SORT_HPP