#include <etl/array.h>
#include <iostream>

int main() {
    etl::array<int, 5> values = {{1, 2, 3, 4, 5}};

    int sum = 0;
    for (size_t i = 0; i < values.size(); ++i) {
        sum += values[i];
    }

    std::cout << "ETL array sum: " << sum << "\n";
    return 0;
}
