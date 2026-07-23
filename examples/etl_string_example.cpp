#include <etl/string.h>
#include <iostream>

int main() {
    etl::string<32> text = "Hello";
    text += ", ETL";
    text += "!";

    std::cout << "ETL string: " << text.c_str() << "\n";
    std::cout << "Length: " << text.size() << "\n";
    return 0;
}
