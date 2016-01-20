// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

class A
{
public:
  A() {cout<<"1";}
  A(const A&) {cout<<"2";}
};
class B: public A
{
public:
  B() {cout<<"3";}
  B(const B&) {cout<<"4";}
};

int main () {

  try {B b; throw b;}
  catch(A&) {cout<<"5"; }
  //catch(B&) {cout<<"6"; }
  catch(...){cout<<"7"; }

  return 0;
}

//13145