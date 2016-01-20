// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;

int main () {

  try
  {
    try
    {
      throw 1;
    }

    catch(double) {cout<<"1"; throw;}
    catch(short) {cout<<"2"; throw;}
    catch(...) {cout<<"3"; throw;} //3
  }
  catch(long) {cout<<"1"; }
  catch(int) {cout<<"2"; } //2
  catch(...){cout<<"3"; }

  return 0;
}

//32