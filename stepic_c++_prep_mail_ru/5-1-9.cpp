// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

class A {};
class B: public A {};

int main () {

  try {throw B();}
  catch(A&) {cout<<"1"; }
  //catch(B&) {cout<<"2"; }
  catch(...){cout<<"3"; }

  return 0;
}

//1