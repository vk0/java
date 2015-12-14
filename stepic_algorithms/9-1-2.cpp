// alias c="g++ --std=c++11 -Wall -Wextra -O2"
//  Практика на C++: Расстояние редактирования

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

int get_levenshtein_distance(const std::string &str1, const std::string &str2) {
    size_t size1 = str1.size();
    size_t size2 = str2.size();

    std::vector <std::vector <int>> d(size1 + 1, std::vector <int>(size2 + 1));
    for (size_t i = 0; i <= size1; i++) {
        for (size_t j = 0; j <= size2; j++) {
            if (i == 0 || j == 0) {
                d[i][j] = i + j;
                continue;
            }
            int insert_distance = d[i][j-1]+1;
            int delete_distance = d[i - 1][j] + 1;
            int match_distance = d[i-1][j-1]+(str1[size1-1] != str2[size2-j]);
            d[i][j] = std::min({insert_distance, delete_distance, match_distance});
        }
    }
    return d[size1][size2];
}

int main(void) {
    std::string str1;
    std::string str2;

    std::cin >> str1 >> str2;
    std::cout << get_levenshtein_distance(str1, str2) << std::endl;
}