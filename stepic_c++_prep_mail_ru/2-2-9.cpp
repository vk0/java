// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;
struct B {
    virtual void f (int a = 5) { g (); cout << a << " - B::f (int) ";}
    void g () {cout << "B::g () ";}
};

class D: public B {
    void f (int b = 6) { g (); cout << b << " - D::f (int) ";}
    virtual void g () {cout << "D::g () ";}
};

int main () {
    D d;
    B b, & rb = d;
    b.f();
    rb.f();
    cout << endl;
    return 0;
}

// B::g () 5 - B::f (int) D::g () 5 - D::f (int)