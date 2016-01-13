// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;
class A {
public:
  int a,b;
public:
  A(int a = 0, int c = 0) {
    this->a = a;
    b = a;
    cout << 1;
  }
  A(const A& x){
    a = x.a;
    b = x.b;
    cout << 2;
  }
  ~A() { cout << 3;}
};

int main() {
  A x(1), y, z = A(2,4), t(3.5,2), s = 6, w = z;
  return 0;
}

//111112333333