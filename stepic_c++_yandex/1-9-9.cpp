// Дано действительное положительное число a и целоe число n.

// Вычислите an. Решение оформите в виде функции power(a, n).

// Формат входных данных
// Вводится действительное положительное число a и целоe число n.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input 1:

// 2
// 1

// Sample Output 1:

// 2


// Sample Input 2:

// 2
// 2

// Sample Output 2:

// 4

#include <iostream>
#include <cmath>

using namespace std;

double power(double a, int n){
    double d = 1;

    if(n != 0){
        if (n > 0){
            for(int i = 0; i < n; i++){
                d *= a;
            }
        }   else {
            d = 1/power(a, -n);
        }
    }   else    {
        d = 1;
    }
    return d;
}

int main(){
    double a;
    int n;
    cin >> a >> n;
    cout << power(a, n);
    return 0;
}