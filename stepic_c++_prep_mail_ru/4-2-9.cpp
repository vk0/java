// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

template <typename T> T f(T a) {
    return a;
}

int main () {
  cout << f(2) <<","<< f<bool>(2)<<","<<f<int>('2'-'1')<<endl;
  return 0;
}

//2,1,1