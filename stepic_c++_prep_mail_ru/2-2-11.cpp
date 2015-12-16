// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

struct B {
    virtual void f(int a = 5) = 0;
    void g() {}
};

class D: public B {
    void f(int b = 6) { g(); cout << b << endl;}
    virtual void g() {}
};

int main () {
    D d;
    B & rb = d;
    rb.f();
    return 0;
}

// 5