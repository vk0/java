#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;
// Вычисляем корни ax2+bx+c=0
int main(void)
{
   double a, b, c;
   setlocale(LC_ALL, "Russian");
   cout<<"Решаем уравнение ax^2+bx+c=0, введите a, b, c: ";
   cin>>a>>b>>c;
   if (a==0.0)
   {
      cout<<"Уравнение вырождено"<<endl;
      return 0;
   }
   double x1, x2, d;
   d=b*b-4*a*c; // Определитель
   if (d<0.0)
      cout<<"Корней нет!"<<endl;
   else if (d==0.0)
      cout<<"x="<<-b/(2*a)<<endl;
   else
   {
      d=sqrt(d); // Корень из определителя
      x1=(-b+d)/(2*a); // Больший корень уравнения
      x2=(-b-d)/(2*a); // Меньший корень уравнения
      cout<<"x1="<<x1<<" x2="<<x2<<endl;
   }
   return 0;
}
