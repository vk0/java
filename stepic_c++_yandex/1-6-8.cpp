// Определите среднее значение всех элементов последовательности, завершающейся числом 0.

// Формат входных данных
// Вводится последовательность целых чисел, оканчивающаяся числом 0 (само число 0 в последовательность не входит, а служит как признак ее окончания).
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input:

// 1
// 7
// 9
// 0

// Sample Output:

// 5.66666666667

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double mid;
    int sum=0, n, i=0;
    cin >> n;
    while(n != 0){
        sum += n;
        i++;
        cin >> n;
    }
    cout << setprecision(11) << fixed ;
    cout << (double) sum/i;
  return 0;
}