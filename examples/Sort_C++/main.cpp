/******************************************************************************
Sort
*******************************************************************************/
#include <iostream>
#include "sort.h"

int main() {
    int arr[] = {10, 6, -1, 9, 77};

    bubble_sort(arr);

    for (auto element : arr) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    return 0;
}

