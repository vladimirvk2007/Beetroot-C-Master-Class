#include <etl/map.h>
#include <iostream>

int main() {
    etl::map<int, int, 8> score_by_id;

    score_by_id[10] = 95;
    score_by_id[20] = 88;
    score_by_id[30] = 91;

    int total = 0;
    for (etl::map<int, int, 8>::const_iterator it = score_by_id.begin(); it != score_by_id.end(); ++it) {
        total += it->second;
    }

    std::cout << "ETL map size: " << score_by_id.size() << "\n";
    std::cout << "Total score: " << total << "\n";
    return 0;
}
