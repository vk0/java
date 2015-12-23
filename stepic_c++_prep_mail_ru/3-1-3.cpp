// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;
struct A {
  static int i;
  static void f(){i=30;}
} a;

int A::i = 10;

void f() {
  A::i = 20;
  A::f();
}

int main() {
  f();
  A::f();
  A::i = 40;
  f();
  cout << a.i <<","<<(&a)->i<<","<<A::i<< endl;
  return 0;
}

//30,30,30