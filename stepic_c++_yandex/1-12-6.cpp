// Выведите все исходные точки в порядке возрастания их расстояний от начала координат.

// Входные данные

// Программа получает на вход набор точек на плоскости. Сначала задано количество точек n, затем идет последовательность из n строк, каждая из которых содержит два числа: координаты точки. Величина n не превосходит 100, все исходные координаты – целые числа, не превосходящие 103.

// Выходные данные

// Необходимо вывести все исходные точки в порядке возрастания их расстояний от начала координат.

// Sample Input:

// 2
// 1 2
// 2 3

// Sample Output:

// 1 2
// 2 3

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct p {
    int x, y;
    double d;
};

bool cmp(p a, p b){
    return a.d < b.d;
}
int main() {
    int n;
    cin >> n ;
    vector <p> arr(n);
    for (int i = 0; i < n; i++){
        p tp;
        int tx, ty;
        cin >> tx >> ty;
        tp.x = tx;
        tp.y = ty;
        tp.d = sqrt(pow(tx, 2) + pow(ty, 2));
        arr[i] = tp;
    }
    sort(arr.begin(), arr.end(), cmp);
    for(int i = 0; i < n; i++){
        p t = arr[i];
        cout << t.x << " " << t.y << endl;
    }
    return 0;
}