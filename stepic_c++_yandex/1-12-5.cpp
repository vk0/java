//  Во время проведения олимпиады каждый из участников получил свой идентификационный номер – натуральное число. Необходимо отсортировать список участников олимпиады по количеству набранных ими баллов.

// Входные данные

// На первой строке дано число N (1 ≤ N ≤ 1000) – количество участников. На каждой следующей строке даны идентификационный номер и набранное число баллов соответствующего участника. Все числа во входном файле не превышают 105.

// Выходные данные

// В выходной файл выведите исходный список в порядке убывания баллов. Если у некоторых участников одинаковые баллы, то их между собой нужно упорядочить в порядке возрастания идентификационного номера.

// Sample Input 1:

// 3
// 101 80
// 305 90
// 200 14

// Sample Output 1:

// 305 90
// 101 80
// 200 14


// Sample Input 2:

// 3
// 20 80
// 30 90
// 25 90

// Sample Output 2:

// 25 90
// 30 90
// 20 80

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct man {
    int num, points;
};

bool cmp(man a, man b) {
    if(a.points == b.points){
        return a.num < b .num;
    }   else
    return a.points > b.points;
}

int main() {
    int n;
    cin >> n;
    vector <man> a(n);
    for (int i = 0; i < n; i++) {
        int tnum, tpoints;
        cin >> tnum >> tpoints;
        man tmp;
        tmp.num = tnum;
        tmp.points = tpoints;
        a[i] = tmp;
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < a.size(); i++) {
        man now = a[i];
        cout << now.num << " " << now.points << endl;
    }
    return 0;
}