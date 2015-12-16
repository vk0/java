// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;
struct A {
    static int a;
};

int A::a = 1;

struct B: A { };

int main() {
    A a; B b1, b2;
    A::a += 1; a.a += 1; b1.a += 1; b2.a +=1; B::a +=1;
    cout << A::a << endl;
}

// 6