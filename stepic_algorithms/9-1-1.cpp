// alias c="g++ --std=c++11 -Wall -Wextra -O2"
//  Практика на C++: Расстояние редактирования

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

int get_levenshtein_distance(const std::string &str1, const std::string &str2) {
    size_t size1 = str1.size();
    size_t size2 = str2.size();
    if (str1.empty() || str2.empty()) {
        return size1 + size2;
    }
    int insert_distance = get_levenshtein_distance(str1, str2.substr(1)) + 1;
    int delete_distance = get_levenshtein_distance(str1.substr(1), str2) + 1;
    int match_distance = get_levenshtein_distance(str1.substr(1), str2.substr(1)) + (str1[0] != str2[0]);
    return std::min({insert_distance, delete_distance, match_distance});
}

int main(void) {
    std::string str1;
    std::string str2;

    std::cin >> str1 >> str2;
    std::cout << get_levenshtein_distance(str1, str2) << std::endl;
}