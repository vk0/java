#include <iostream>

using namespace std;

int main(void)
{
   int h1, m1, h2, m2;
   // Ввод исходных данных
   cout<<"Enter departure time (hh mm): ";
   cin>>h1>>m1;
   cout<<"Enter in-way time (hh mm): ";
   cin>>h2>>m2;
   // Вычисление результата
   int d3, h3, m3;
   m3=(m1+m2)%60;
   // Дополнительный час (промежуточная переменная)
   int hext=(m1+m2)/60;
   h3=(h1+h2+hext)%24;
   d3=1+(h1+h2+hext)/24;
   // Вывод результата
   cout<<"Arrival time: day "<<d3<<", "<<h3<<":"<<m3<<endl;
   return 0;
}
