#include <etl/vector.h>
#include <iostream>

int main() {
    etl::vector<int, 8> values;

    for (int i = 1; i <= 5; ++i) {
        values.push_back(i * 10);
    }

    std::cout << "ETL vector contents: ";
    for (size_t i = 0; i < values.size(); ++i) {
        std::cout << values[i] << (i + 1 < values.size() ? ", " : "\n");
    }

    return 0;
}
