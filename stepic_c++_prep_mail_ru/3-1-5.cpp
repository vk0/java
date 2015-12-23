// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;
void f(int){cout<<1;}
void f(float){cout<<2;}
void f(double){cout<<3;}
void f(long double){cout<<4;}
int main () {
  f(12.5);
  return 0;
}