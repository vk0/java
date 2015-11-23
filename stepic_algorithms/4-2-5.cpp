// alias c="g++ --std=c++11 -Wall -Wextra -O2"

#include <cassert>
#include <iostream>
#include <vector>

class Fibonacci final {
public:
    static int get(int n) {
        assert(n >= 0);
        static std::vector<int> cache;
        cache.resize(n + 1);
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i <= n; i++) {
            cache[i] = cache[i - 2] + cache[i - 1];
        }
        return cache[n];
    }
};

int main(void) {
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}