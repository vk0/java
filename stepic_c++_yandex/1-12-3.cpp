// Отсортируйте массив.

// Входные данные

// Первая строка входных данных содержит количество элементов в массиве N ≤ 105. Далее идет N целых чисел, не превосходящих по абсолютной величине 109.

// Выходные данные

// Выведите эти числа в порядке неубывания.

// Sample Input:

// 5
// 5 4 3 2 1

// Sample Output:

// 1 2 3 4 5

#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    multiset<int> x;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        x.insert(t);
    }
    for(auto n : x){
        cout << n << " ";
    }
    return 0;
}