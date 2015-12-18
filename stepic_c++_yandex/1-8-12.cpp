// По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m “змейкой”, как показано в примере.
// Формат входных данных

// Вводятся два числа n и m, каждое из которых не превышает 20.
// Формат выходных данных

// Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.

// Sample Input:

// 3 5

// Sample Output:

//    1   2   3   4   5
//   10   9   8   7   6
//   11  12  13  14  15

#include <iostream>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    int a[100][100];
    int c = 1, dir = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j ++){
            if(dir == 1){
                a[i][j] = c;
            }   else    {
                a[i][m-j-1] = c;
            }
            c++;
        }
        dir *= -1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout.width(4);
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}