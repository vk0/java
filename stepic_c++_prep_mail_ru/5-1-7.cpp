// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

struct A
{
  A(){cout<<"1"; throw 1.2;}
  ~A(){cout<<"2";}
};

int main () {

  try {A a;}
  catch(int) {cout<<"3"; }
  catch(float) {cout<<"4"; }
  catch(...){cout<<"5"; }

  return 0;
}

//15