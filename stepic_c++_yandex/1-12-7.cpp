// Выведите фамилии и имена учащихся в порядке убывания их среднего балла.

// Входные данные

// Заданы сначала количество учащихся n, затем n строк, каждая из которых содержит фамилию, имя и три числа (оценки по трем предметам: математике, физике, информатике). Данные в строке разделены одним пробелом. Оценки принимают значение от 1 до 5.

// Выходные данные

// Необходимо вывести пары фамилия-имя по одной на строке, разделяя фамилию и имя одним пробелом. Выводить оценки не нужно. Если несколько учащихся имеют одинаковые средние баллы, то их нужно выводить в порядке, заданном во входных данных.

// Sample Input:

// 3
// Markov Valeriy 5 5 5
// Sergey Petrov 1 1 1
// Petrov Petr 3 3 3

// Sample Output:

// Markov Valeriy
// Petrov Petr
// Sergey Petrov

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

struct man {
    string name, surname;
    int x, y, z, num, tr;
};

bool cmp(man a, man b){
    if(a.tr == b.tr){
        return a.num < b.num;
    }   else
    return a.tr > b.tr;
}

int main() {
    int n;
    cin >> n ;
    vector <man> arr(n);
    for (int i = 0; i < n; i++){
        man temp;
        string tn, ts;
        int tx, ty, tz;

        cin >> ts >> tn;
        cin >> tx >> ty >> tz;

        temp.surname = ts;
        temp.name = tn;

        temp.x = tx;
        temp.y = ty;
        temp.z = tz;
        temp.tr = tx + ty + tz;
        temp.num = i;

        arr[i] = temp;
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < n; i++){
        man t = arr[i];
        cout << t.surname << " " << t.name << endl;
    }

    return 0;
}