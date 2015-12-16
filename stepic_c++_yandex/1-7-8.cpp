// Выведите значение наименьшего из всех положительных элементов в массиве. Известно, что в массиве есть хотя бы один положительный элемент.

// Формат входных данных
// В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input:

// 5
// 5 -4 3 -2 1

// Sample Output:

// 1

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
    // input
    int n;
    cin >> n;
    vector <int> a;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if (temp > 0)
            a.push_back(temp);
    }
    // processing
    int min=a[0];
    for (int i = 1; i < a.size(); i++){
        if (a[i] < min){
            min=a[i];
        }
    }
    // output
    cout << min;
  return 0;
}