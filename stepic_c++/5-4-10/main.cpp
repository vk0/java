// В заголовочном файле foo.hpp есть определение функции:
// void foo(int i) { std::cout << "i = " << i << std::endl; }
// В программе есть три корректных файла с кодом first.cpp, second.cpp и third.cpp, которые подключают foo.hpp.
// Отметьте все верные утверждения из списка.

// Файлы first.cpp, second.cpp и third.cpp компилируются без проблем.
// На этапе компоновки возникает ошибка из-за множественного определения функции foo.

#include <iostream>
using namespace std;

#include "foo.hpp"
int main()
{
    void(5);
    return 0;

}