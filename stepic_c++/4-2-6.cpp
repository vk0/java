// Есть три версии функции foo:

// void foo(char) { std::cout << "char" << std::endl; }
// void foo(signed char) { std::cout << "signed char" << std::endl; }
// void foo(unsigned char) { std::cout << "unsigned char" << std::endl; }
// Отметьте все верные утверждения относительно вызова функции foo.

#include <iostream>
#include <string>
using namespace std;

void foo(char) { std::cout << "char" << std::endl; }
void foo(signed char) { std::cout << "signed char" << std::endl; }
void foo(unsigned char) { std::cout << "unsigned char" << std::endl; }

int main() {
    foo('a'); //в результате вызова foo('a') будет выведено char
   //foo(97); //вызов foo(97) приведет к ошибке компиляции
    return 0;
}