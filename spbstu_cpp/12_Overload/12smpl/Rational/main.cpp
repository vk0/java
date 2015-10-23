#include "rational.h"
#include <locale.h>

int main(void)
{
   setlocale(LC_ALL, "Russian");
   Rational a(1,2), b(-1,6);
   cout<<"a="<<a<<" b="<<b<<" a+b="<<a+b<<endl;
   cout<<"a("<<a<<") *= b("<<b<<")"<<endl;
   a *= b;
   cout<<"a="<<a<<" b="<<b<<" a-b="<<a-b<<endl;
   Rational c=3;
   cout<<"b="<<b<<" c="<<c<<" b/c="<<b/c<<endl;
   Rational z=5;
   z++;
   ++z;
   cout<<"Введите рациональное число d=m/n в формате: m n"<<endl;
   Rational d;
   cin>>d;
   cout<<"b("<<b<<") -= c("<<c<<")"<<endl;
   b -= c;
   cout<<"b="<<b<<" d="<<d<<" b*d="<<b*d<<endl;
   cout<<"c("<<c<<") += a("<<a<<")"<<endl;
   c += a;
   cout<<"c="<<c<<" (int)c="<<(int)c<<" (double)c="<<(double)c<<endl;
   Rational e(7,8), f(5,12);
   cout<<"e="<<e<<" f="<<f<<" e+f=?"<<endl;
   cout<<"Введите результат g=m/n в формате: m n"<<endl;
   Rational g;
   cin>>g;
   if (e+f!=g)
      cout<<"Неправильно! e+f="<<e+f<<endl;
   else
      cout<<"Правильно!"<<endl;
   return 0;
}