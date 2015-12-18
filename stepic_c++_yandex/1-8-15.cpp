// По данным числам n и m заполните двумерный массив размером n×m числами от 1 до n×m по спирали, выходящей из левого верхнего угла и закрученной по часовой стрелке, как показано в примере.
// Формат входных данных

// Вводятся два числа n и m, не превышающие 100.
// Формат выходных данных

// Выведите полученный массив, отводя на вывод каждого элемента ровно 4 символа.

// Sample Input:

// 4 5

// Sample Output:

//    1   2   3   4   5
//   14  15  16  17   6
//   13  20  19  18   7
//   12  11  10   9   8

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n, m, a[50][50];
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            a[i][j] = -1;
        }
    }
    int dir = 0, di = 0, dj = 1, i = 0, j = 0;
    for(int c = 1; c <= n * m; c++){
        if (a[i][j] == -1){
            a[i][j] = c;
        }
        if(a[i + di][j + dj] != -1){
            dir = (dir + 1) % 4;
        }
        switch (dir){
            case 0 :
                di = 0;
                dj = 1;
                break;
            case 1 :
                di = 1;
                dj = 0;
                break;
            case 2 :
                di = 0;
                dj = -1;
                break;
            case 3 :
                di = -1;
                dj = 0;
                break;
            default :
                break;
        }
        i +=di;
        j +=dj;
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cout.width(4);
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}