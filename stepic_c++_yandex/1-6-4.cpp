// Дано положительное действительное число X. Выведите его первую цифру после десятичной точки.

// Формат входных данных
// Вводится положительное действительное число.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input:

// 1.79

// Sample Output:

// 7

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double x;
    cin >> x;
    x *=10;
    x = trunc(x);
    x = fmod(x, 10);
    cout << x;
  return 0;
}