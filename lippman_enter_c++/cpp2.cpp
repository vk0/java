#include <iostream>

int main()
{
    int sum = 0, value;
    while (std::cin >> value) {
        sum += value;
    }
    std::cout << "Sum is: " sum << std::endl;
    return 0;
}
