// Дан массив. Выведите те его элементы, которые встречаются в массиве только один раз. Элементы нужно выводить в том порядке, в котором они встречаются в списке.

// Формат входных данных
// В первой строке вводится количество элементов в массиве. Во второй строке вводятся элементы массива.
// Формат выходных данных
// Выведите ответ на задачу.

// Sample Input 1:

// 6
// 1 2 2 3 3 3

// Sample Output 1:

// 1


// Sample Input 2:

// 8
// 4 3 5 2 5 1 3 5

// Sample Output 2:

// 4 2 1

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool found(vector <int> a, int b){
    bool t = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b){
            t = 1;
            break;
        }
    }
    return t;
}

int main(){
    int x;
    cin >> x;
    vector <int> a(x), sol;
    for(int i = 0; i < x; i++){
        cin >> a[i];
    }
    for(int i = 0; i < x; i++){
        int t = a[i];
        a[i] = 0;
        if(!found(a, t)){
            sol.push_back(t);
        }
        a[i] = t;
    }
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << " ";
    }
    return 0;
}