#include <etl/vector.h>
#include <iostream>

int main() {
    etl::vector<int, 8> values;

    values.push_back(10);
    values.push_back(20);
    values.push_back(30);

    values.insert(values.begin() + 1, 15);

    std::cout << "size=" << values.size() << ", max_size=" << values.max_size() << "\n";
    std::cout << "front=" << values.front() << ", back=" << values.back() << "\n";

    std::cout << "items: ";
    for (etl::vector<int, 8>::const_iterator it = values.begin(); it != values.end(); ++it) {
        std::cout << *it << (it + 1 != values.end() ? ", " : "\n");
    }

    values.erase(values.begin());
    values.pop_back();

    std::cout << "after erase/pop, size=" << values.size() << "\n";

    values.clear();
    std::cout << "empty=" << (values.empty() ? "true" : "false") << "\n";

    return 0;
}
