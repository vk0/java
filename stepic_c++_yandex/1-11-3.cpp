// Дан список целых чисел, который может содержать до 100000 чисел. Определите, сколько в нем встречается различных чисел.

// Входные данные

// Вводится число N - количество элементов списка, а затем N чисел.

// Выходные данные

// Выведите ответ на задачу.

// Sample Input:

// 5
// 1 2 3 2 1

// Sample Output:

// 3

#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
    return 0;
}