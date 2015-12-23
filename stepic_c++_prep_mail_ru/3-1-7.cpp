// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

void f(float a = 2.5, short b = 3.14){cout<<1;}
void f(float a = 3, int b = 5){cout<<2;}
void f(long double a = 2, short b = true){cout<<3;}
int main () {

  f(2.5, true);
  return 0;
}