// Нужно посчитать, сколько всего раз будет вызвана функция foo, если ее вызвать с аргументом 3 (т.е. foo(3)). Самый первый вызов тоже нужно посчитать.
#include <iostream>
#include <cstdio>
using namespace std;

int foo(int n, int& counter) {
    counter++;
    if (n <= 0)
        return 1;
        return foo((n * 2) / 3,counter) + foo(n - 2,counter);
}

int main() {
    int counter = 0;
    // printf ("%i",foo(3,counter));
    cout << "Foo result: "<< foo(3,counter) << endl;
    cout << "How many recursive calls: " << counter << endl;
}