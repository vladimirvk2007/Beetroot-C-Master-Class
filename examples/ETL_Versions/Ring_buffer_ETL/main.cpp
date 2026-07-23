#include <etl/array.h>
#include <cstddef>
#include <cstdint>
#include <iostream>

class RingBufferEtl {
public:
    static constexpr std::size_t kCapacity = 8;

    bool push(uint8_t value) {
        if (count_ == kCapacity) {
            return false;
        }

        buffer_[head_] = value;
        head_ = (head_ + 1) % kCapacity;
        ++count_;
        return true;
    }

    bool pop(uint8_t& out) {
        if (count_ == 0) {
            return false;
        }

        out = buffer_[tail_];
        tail_ = (tail_ + 1) % kCapacity;
        --count_;
        return true;
    }

    bool empty() const { return count_ == 0; }
    bool full() const { return count_ == kCapacity; }

private:
    etl::array<uint8_t, kCapacity> buffer_{};
    std::size_t head_ = 0;
    std::size_t tail_ = 0;
    std::size_t count_ = 0;
};

int main() {
    RingBufferEtl buff;
    const uint8_t input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (std::size_t i = 0; i < (sizeof(input) / sizeof(input[0])); ++i) {
        if (!buff.push(input[i])) {
            std::cout << "Buffer overflow at index " << i << "\n";
            break;
        }
        std::cout << "Pushed " << static_cast<int>(input[i]) << "\n";
    }

    uint8_t value = 0;
    while (buff.pop(value)) {
        std::cout << "Popped " << static_cast<int>(value) << "\n";
    }

    return 0;
}
