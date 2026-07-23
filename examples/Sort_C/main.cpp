/******************************************************************************
Sort
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include "sort.h"


int main()
{
    int cnt = 0;
    int arr_int[] = {10, 6, -1, 9, 77};
    size_t size = sizeof(arr_int)/sizeof(int);

    bubble_sort(arr_int, size);

    for (cnt = 0; cnt < size; cnt++) {
        printf("%d ", arr_int[cnt]);
    }

    printf("\n");

    return 0;
}


