// Что будет напечатано в результате работы программы?

#include <iostream>
using namespace std;

int main () {

  try
  {
    throw "a";
  }

  catch(char) {cout<<"1";}
  catch(const char *) {cout<<"2";}
  catch(...) {cout<<"3";}

  return 0;
}

//2