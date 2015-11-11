// Задача на программирование: покрыть отрезки точками


// По данным n отрезкам необходимо найти множество точек минимального размера, для которого каждый из отрезков содержит хотя бы одну из точек.

// В первой строке дано число 1≤n≤100 отрезков. Каждая из последующих n строк содержит по два числа 0≤l≤r≤109, задающих начало и конец отрезка. Выведите оптимальное число m точек и сами m точек. Если таких множеств точек несколько, выведите любое из них.

// Sample Input 1:

// 3
// 1 3
// 2 5
// 3 6

// Sample Output 1:

// 1
// 3


// Sample Input 2:

// 4
// 4 7
// 1 3
// 2 5
// 5 6

// Sample Output 2:

// 2
// 3 6

#include <iostream>
#include <algorithm>
using namespace std;

struct Segment {
    int l;
    int r;
};

bool segcmp(Segment seg1, Segment seg2);

int main() {
    int n;
    cin >> n;
    Segment a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i].l >> a[i].r;

    sort(a, a + n, segcmp);

    // sort check begin
    //cout << endl;
    //for (int i = 0; i < n; ++i)
    //    cout << a[i].l << " " << a[i].r << endl;
    // sort check end

    int cnt = 1;
    int dots[n];
    fill(dots, dots + n, 0);
    dots[cnt - 1] = a[0].r;
    int i = 1;
    while (i < n) {
        while ((i < n) && (a[i].l <= dots[cnt - 1]))
            i++;
        if (i < n) {
            cnt++;
            dots[cnt - 1] = a[i].r;
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i)
		cout << dots[i] << " " << endl;

    return 0;
}

bool segcmp(Segment seg1, Segment seg2) {
    return seg1.r < seg2.r;
}
