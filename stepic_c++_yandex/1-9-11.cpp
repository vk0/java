// Дано натуральное число n > 1. Проверьте, является ли оно простым. Программа должна вывести слово YES, если число простое и NO, если число составное.
// Решение оформите в виде функции IsPrime(n), которая возвращает True для простых чисел и False для составных чисел. Количество операций в программе должно быть пропорционально корню из n.
// Формат входных данных
// Вводится натуральное число.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input 1:

// 2

// Sample Output 1:

// YES


// Sample Input 2:

// 4

// Sample Output 2:

// NO

#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int n){
    int min = -1;
    for(int i = 2; i <= (double)sqrt(n); i++){
        if(n % i == 0){
            min = i;
            break;
        }
    }
    return min == -1;

}

int main(){
    int n;
    cin >> n;
    if(IsPrime(n)){
        cout << "YES";
    }   else {
        cout << "NO";
    }
    return 0;
}