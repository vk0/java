// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

class A {
    int a;
public:
    A() { a = 5; }
    int f(int x) { a = x; return x;}
    void show_a(){ cout << a << endl; }
};

class B: public A {
public:
    void g() { A::f(7); }
};


int main() {
    B obj;
    obj.g();
    obj.show_a();
}