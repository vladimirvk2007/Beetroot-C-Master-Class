/******************************************************************************
Ring Buffer. Test program.
*******************************************************************************/

#include <iostream>
#include "ring_buffer.h"

using namespace std;

int main() {
    RingBuffer<uint8_t, 8> buff;

    const uint8_t tmp_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    uint8_t tmp_uint = 0;

    // Тест Push
    for (size_t cnt = 0; cnt < sizeof(tmp_arr); cnt++) {
        if (!buff.push(tmp_arr[cnt])) {
            cout << "Buffer overflow, cnt = " << cnt << "\n";
            break;
        } else {
            cout << "Pushed data = " << static_cast<int>(tmp_arr[cnt]) << "\n";
        }
    }

    // Тест Pop
    for (size_t cnt = 0; cnt < sizeof(tmp_arr); cnt++) {
        if (!buff.pop(tmp_uint)) {
            cout << "Buffer is empty, cnt = " << cnt << "\n";
            break;
        } else {
            cout << "Popped data = " << static_cast<int>(tmp_uint) << "\n";
        }
    }

    return 0;
}

