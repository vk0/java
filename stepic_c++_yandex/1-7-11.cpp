// Переставьте соседние элементы массива (A[0] c A[1], A[2] c A[3] и т.д.). Если элементов нечетное число, то последний элемент остается на своем месте.

// Формат входных данных
// В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input:

// 5
// 1 2 3 4 5

// Sample Output:

// 2 1 4 3 5

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    // input
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // processing
    for (int i = 0; i < n-1; i += 2){
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
    // output
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
  return 0;
}