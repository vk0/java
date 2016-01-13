// Что будет напечатано в результате работы следующей программы?

#include <iostream>
using namespace std;
template <typename T> void f(T) { cout <<0;}
template<> void f(int) {cout<<1;}
template<> void f(double) {cout<<2;}

int main () {
    f(1); f(0); f(1.0); f(true);
    return 0;
}

//1120