// Дан список, упорядоченный по неубыванию элементов в нем. Определите, сколько в нем различных элементов.

// Формат входных данных
// В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input:

// 6
// 1 2 2 3 3 3

// Sample Output:

// 3

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    // input
    int n, temp, count=0;
    cin >> n;
    vector <int> a(n);
    cin >> a[0];
    temp=a[0];
    count++;
    for (int i = 1; i < n; i++){
        cin >> a[i];
        if(a[i] != temp) {
            temp = a[i];
            count++;
        }
    }
    // processing
    // output
    cout << count;
  return 0;
}