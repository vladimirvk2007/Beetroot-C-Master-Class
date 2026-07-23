#include <etl/array.h>
#include <iostream>

int main() {
    etl::array<int, 5> values = {{1, 2, 3, 4, 5}};

    std::cout << "size=" << values.size() << ", max_size=" << values.max_size() << "\n";
    std::cout << "front=" << values.front() << ", back=" << values.back() << "\n";

    values[0] = 10;
    values.at(1) = 20;

    int sum = 0;
    for (etl::array<int, 5>::const_iterator it = values.begin(); it != values.end(); ++it) {
        sum += *it;
    }
    std::cout << "sum=" << sum << "\n";

    values.fill(7);
    std::cout << "after fill: ";
    for (size_t i = 0; i < values.size(); ++i) {
        std::cout << values[i] << (i + 1 < values.size() ? ", " : "\n");
    }

    etl::array<int, 5> other = {{9, 9, 9, 9, 9}};
    values.swap(other);
    std::cout << "after swap front=" << values.front() << "\n";

    return 0;
}
