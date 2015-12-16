// Циклически сдвиньте элементы списка вправо (A[0] переходит на место A[1], A[1] на место A[2], ..., последний элемент переходит на место A[0]).

// Формат входных данных
// В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input:

// 5
// 1 2 3 4 5

// Sample Output:

// 5 1 2 3 4

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    // input
    int n;
    cin >> n;
    vector <int> a(n+1);
    a[0]=0;
    for (int i = 1; i < n + 1; i++){
        cin >> a[i];
    }
    // processing
    a[0] = a[n];
    // output
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
  return 0;
}