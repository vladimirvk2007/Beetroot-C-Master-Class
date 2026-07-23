#include <etl/map.h>
#include <iostream>

int main() {
    etl::map<int, int, 8> score_by_id;

    score_by_id[10] = 90;
    score_by_id[20] = 85;
    score_by_id[30] = 95;

    std::cout << "size=" << score_by_id.size() << ", max_size=" << score_by_id.max_size() << "\n";
    std::cout << "count(20)=" << score_by_id.count(20) << "\n";

    etl::map<int, int, 8>::iterator it = score_by_id.find(30);
    if (it != score_by_id.end()) {
        std::cout << "id=30 score=" << it->second << "\n";
    }

    score_by_id.erase(20);

    std::cout << "items after erase: ";
    for (etl::map<int, int, 8>::const_iterator i = score_by_id.begin(); i != score_by_id.end(); ++i) {
        std::cout << "{" << i->first << ":" << i->second << "}";
    }
    std::cout << "\n";

    score_by_id.clear();
    std::cout << "empty=" << (score_by_id.empty() ? "true" : "false") << "\n";

    return 0;
}
