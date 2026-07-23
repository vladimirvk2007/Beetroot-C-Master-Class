#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int arr[], size_t size)
{
    int i = 0, j = 0, cnt = 0;
    int tmp_int = 0;
    bool swapped = false;

    for (i = 0; i < size -1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                tmp_int = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp_int;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}
