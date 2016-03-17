// Что будет напечатано в результате работы следующей программы?

#include <iostream>

class A {
    A() { std::cout << "A"; }
};

int main()
{
    A a, b;
    return 0;
}

// Ошибка компиляции