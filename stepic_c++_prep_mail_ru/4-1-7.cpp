// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

int i = 3;

class Test{
public:
  int i;
  void f() { i = 2;}
};

int main(){
  cout << i;
  i = 1;
  Test i;
  i.f();
  cout << i.i << endl;
}

//32