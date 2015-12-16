// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

struct A {
    static int i;
};

int A::i = 10;

void f() {
    A::i = 20;
}

int main () {
    A a, *pa = &a;
    a.i = 0;
    pa->i = 1;
    (*pa).i = 2;
    (&a)->i = 3;
    A::i = 4;
    f();
    cout << a.i <<" "<< pa->i <<" "<<(*pa).i<<" "<<(&a)->i<<" "<<A::i<< endl;
    return 0;
}

// 20 20 20 20 20