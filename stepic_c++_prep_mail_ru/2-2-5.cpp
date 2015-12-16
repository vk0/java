// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

class A {
protected:
    int a,b;
public:
    void set_ab(int n, int m) {
    a = m;
    b = n;
  }
};
class B: public A {
    int c;
public:
    void set_c(int n) { c = n; }
    void show_abc() {
    cout << a << b << c << endl;
  }
};


int main() {
    B obj;
    obj.set_ab(1,3);
    obj.set_c(2);
    obj.show_abc();
}

// 312