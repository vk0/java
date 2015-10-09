// В программе определены две функции:

// float  square(float value) { return value * value; }
// double square(float value) { return (double)value * value; }
// Далее в программе есть вызов:

// double sq = square(2.0);
// Отметьте все верные утверждения из списка.

#include <iostream>
#include <string>
using namespace std;

float  square(float value) { return value * value; }
//программа не скомпилируется, потому что такая перегрузка функции square не допустима
double square(float value) { return (double)value * value; }

int main() {
    double sq = square(2.0); //
    std::cout << sq << std::endl;
    return 0;
}