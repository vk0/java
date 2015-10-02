// Вам требуется написать программу, которая "переворачивает" последовательность положительных целых чисел. На вход подается последовательность разделенных пробелами положительных целых чисел. Последовательность заканчивается нулем. Требуется вывести эту последовательность в обратном порядке.

// На выводе числа нужно так же разделить пробелами. Завершающий ноль — это просто индикатор конца последовательности, он не является ее частью, т.е. выводить его не нужно.

// Требования к реализации: в данном задании запрещено использовать циклы, а также дополнительную память: массивы, строки или контейнеры (даже, если вы с ними уже знакомы). Вам разрешено заводить вспомогательные функции, если они вам нужны.

// Подсказка: используйте рекурсию.

// Sample Input:
// 15 26 1 42 0
// Sample Output:
// 42 1 26 15

#include <iostream>
#include <cstdio>
using namespace std;

void reverse(int number){
    if(number == 0) //base/basic case i.e if number is zero the problem is already solved, nothing to do, so simply return
        return;
    else{
        cout << number % 10; // print that last digit, e.g 103%10 == 3
        reverse(number/10); //solve the same problem but with smaller number, i.e make the problem smaller by dividing it by 10,  initially we had 103, now 10
    }
}

int main() {
    int c = 0;
    while(!(std::cin >> c ) || c != 0){
        cout << reverse(c);
}
}
// int reverse(int n) {
//     if (n = 0)
//         return 1;
//     return reverse(n);
//         // return foo((n * 2) / 3,counter) + foo(n - 2,counter);
// }

// int main()
// {
//     int c = 0;
//     while(!(std::cin >> c ) || c != 0){
//         cout << reverse(c);
//         // cout << c;
//     // while (cin.get(c)) {
//     //         cout << reverse(c);
//     //         // cout << c;
//         }
//     return 0;
// }