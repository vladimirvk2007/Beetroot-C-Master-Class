#include <cstdint>
#include <cstddef>

template <typename T, std::size_t Size>

class RingBuffer {
private:
    T m_buffer[Size];
    std::size_t m_head;
    std::size_t m_tail;
    std::size_t m_count;

public:
    RingBuffer() : m_head(0), m_tail(0), m_count(0) {}

    bool is_full() const {
        return m_count == Size;
    }

    bool is_empty() const {
        return m_count == 0;
    }

    bool push(T data) {
        if (is_full()) {
            return false;
        }
        m_buffer[m_head] = data;
        m_head = (m_head + 1) % Size;
        m_count++;
        return true;
    }

    bool pop(T& data) {
        if (is_empty()) {
            return false;
        }
        data = m_buffer[m_tail];
        m_tail = (m_tail + 1) % Size;
        m_count--;
        return true;
    }
};

