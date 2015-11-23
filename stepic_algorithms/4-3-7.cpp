// alias c="g++ --std=c++11 -Wall -Wextra -O2"

#include <cassert>
#include <cstdint>
#include <utility>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
    assert(a > 0 && b > 0);

    while (b > 0) {
        a %= b;
        std::swap(a,b);
    }
    return a;
}

int main(void) {
    std::int64_t a,b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}