// alias c="g++ --std=c++11 -Wall -Wextra -O2"
// Практика на C++: Двоичный поиск

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int> &numbers, int number) {
    size_t l = 0;
    size_t r = numbers.size();
    while (l + 1 < r) {
        size_t m = l + (r - l) / 2;
        if (numbers[m] > number) {
            r = m;
        } else {
            l = m;
        }
    }
    if ( l == r || numbers[l] != number) {
        return -1;
    }
    return l + 1;
}

int main(void) {
    std::vector<int> numbers;
    size_t number_count;
    std::cin >> number_count;
    numbers.resize(number_count);
    for (auto &number:numbers) {
        std::cin >> number;
    }
    assert(std::is_sorted(numbers.begin(), numbers.end()));

    size_t query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int number;
        std::cin >> number;
        std::cout << get_pos(numbers, number) << " ";
    }
    std::cout << std::endl;
}