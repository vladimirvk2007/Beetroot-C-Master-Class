#include <etl/string.h>
#include <iostream>

int main() {
    etl::string<32> text = "API";

    text += " demo";
    text.append(" for ETL");
    text.push_back('!');

    std::cout << "text=\"" << text.c_str() << "\"\n";
    std::cout << "size=" << text.size() << ", max_size=" << text.max_size() << "\n";

    size_t pos = text.find("demo");
    if (pos != etl::string<32>::npos) {
        text.erase(pos, 4);
        text.insert(pos, "example");
    }

    text.pop_back();
    std::cout << "updated=\"" << text.c_str() << "\"\n";

    return 0;
}
