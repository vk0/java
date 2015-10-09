// В программе есть следующие определения:

// void promotion(char &) { std::cout << "char" << std::endl; }
// void promotion(int  &) { std::cout << "int"  << std::endl; }
// void promotion(long &) { std::cout << "long" << std::endl; }
// Кроме того в программе есть вызов:

// short sh = 10;
// promotion(sh);
// Отметьте все верные утверждения.

#include <iostream>
#include <string>
using namespace std;

void promotion(char &) { std::cout << "char" << std::endl; }
void promotion(int  &) { std::cout << "int"  << std::endl; }
void promotion(long &) { std::cout << "long" << std::endl; }

int main() {
    short sh = 10;
    promotion(sh); //вызов promotion(sh) не скомпилируется, так как нет ни одной подходящей функции для вызова
    return 0;
}