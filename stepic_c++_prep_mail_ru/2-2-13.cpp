// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

class A { public: int* n; int m; };
class B: virtual public A { public: int* p; };
class C: virtual public A { public: int* c; };
class D: public B, public C { public: int* e; };

int main () {
    D fA, * f = new D;
    f->m = 0;
    fA.m = 1;
    cout << fA.m << " " << (*f).m << endl;
    return 0;
}

// 1 0