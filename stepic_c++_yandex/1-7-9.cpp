// Выведите значение наименьшего нечетного элемента списка, а если в списке нет нечетных элементов - выведите число 0.

// Формат входных данных
// В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input 1:

// 5
// 0 1 2 3 4

// Sample Output 1:

// 1


// Sample Input 2:

// 5
// 2 4 6 8 10

// Sample Output 2:

// 0

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
        int s=abs(temp);
        if (s%2 == 1)
            a.push_back(temp);
    }
    // processing
    if(a.size() > 0){
        int min=a[0];
        for (int i = 1; i < a.size(); i++){
            if (a[i] < min){
                min=a[i];
            }
        }
        cout << min;
    } else cout << 0;
    // output
  return 0;
}