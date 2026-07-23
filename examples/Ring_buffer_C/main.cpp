/******************************************************************************
Ring Buffer. Test program.
*******************************************************************************/

#include <stdio.h>
#include "ring_buffer.h"


int main()
{
    uint8_t tmp_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int cnt = 0;
    RingBuffer buff = {0};
    int ret = 0;

    rb_init(&buff);

    for (cnt = 0; cnt < (int)(sizeof(tmp_arr) / sizeof(tmp_arr[0])); cnt++) {
        ret = rb_push(&buff, tmp_arr[cnt]);
        if (0 != ret) {
            printf("Buffer overflow, cnt = %d\n", cnt);

            break;
        } else {
            printf("Pushed data = %u\n", tmp_arr[cnt]);
        }
    }

    return 0;
}

