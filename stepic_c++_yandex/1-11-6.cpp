// Даны два списка чисел, которые могут содержать до 100000 чисел каждый.  Выведите все числа, которые входят как в первый, так и во второй список в порядке возрастания.

// Входные данные

// Вводится число N - количество элементов первого списка, а затем N чисел первого списка.

// Затем вводится число M - количество элементов второго списка, а затем M чисел второго списка.

// Выходные данные

// Выведите ответ на задачу.

// Sample Input:

// 3
// 1 3 2
// 3
// 4 3 2

// Sample Output:

// 2 3

#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> x;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        x.insert(t);
    }
    int m;
    cin >> m;
    set<int> y, z;
    for(int i = 0; i < m; i++){
        int t;
        cin >> t;
        y.insert(t);
        if(x.find(t) != x.end() && y.find(t) != y.end()){
            z.insert(t);
        }
    }
    for(auto now : z){
        cout << now <<" ";
    }
    return 0;
}