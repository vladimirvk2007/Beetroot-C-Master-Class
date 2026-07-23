#include <cstdint>
#include <cstddef>


template <typename T, std::size_t Size>
class Stack {
private:
    T m_buffer[Size];
    std::size_t m_top;

public:
    Stack() : m_top(0) {}

    bool is_full() const {
        return m_top == Size;
    }

    bool is_empty() const {
        return m_top == 0;
    }

    bool push(T data) {
        if (is_full()) {
            return false;
        }
        m_buffer[m_top] = data;
        m_top++;
        return true;
    }

    bool pop(T& data) {
        if (is_empty()) {
            return false;
        }
        m_top--;
        data = m_buffer[m_top];
        return true;
    }
    
    bool peek(T& data) const {
        if (is_empty()) {
            return false;
        }
        data = m_buffer[m_top - 1];
        return true;
    }
};
