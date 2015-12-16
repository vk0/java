// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

class A {
public:
    mutable int i;
    A(int j = 1) { i = 2;}
    int f() const { return i;}
};

int main() {
    const A a(4);
    a.i = 3;
    a.f();
    cout << a.i << endl;
}

// 3