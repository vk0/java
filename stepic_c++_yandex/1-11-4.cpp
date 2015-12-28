//  Во входной строке записана последовательность чисел через пробел. Для каждого числа выведите слово YES (в отдельной строке), если это число ранее встречалось в последовательности или NO, если не встречалось.

// Входные данные

// Вводится число N - количество элементов списка, а затем N чисел.

// Выходные данные

// Выведите ответ на задачу.

// Sample Input:

// 6
// 1 2 3 2 3 4

// Sample Output:

// NO
// NO
// NO
// YES
// YES
// NO

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
        if(s.find(x) !=  s.end()){
            cout << "YES\n" ;
        }   else    {
            s.insert(x);
            cout << "NO\n";
        }
    }
    return 0;
}