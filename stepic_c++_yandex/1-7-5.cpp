// Найдите количество положительных элементов в данном массиве.

// Формат входных данных
// В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input:

// 5
// 1 -2 3 -4 5

// Sample Output:

// 3

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    // input
    int n, count=0;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // processing
    for (int i = 0; i < n; i++){
        if (a[i] > 0)
            count ++;
    }
    // output
    cout << count;
  return 0;
}