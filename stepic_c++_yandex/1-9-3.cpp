// Напишите функцию min(a, b), вычисляющую минимум двух чисел. Затем напишите функцию min4(a, b, c, d), вычисляющую минимум 4 чисел с помощью функции min. Считайте четыре целых числа и выведите их минимум.
// Формат входных данных
// Вводятся четыре целых числа.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input:

// 4
// 5
// 6
// 7

// Sample Output:

// 4

#include <iostream>
#include <cmath>
using namespace std;
int min(int a, int b){
    if(a>b)
        return b;
    else return a;
}
int min4(int a, int b, int c, int d){
    return min(min(a, b), min(c, d));
}
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min4 (a, b, c, d);

  return 0;
}