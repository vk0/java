#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
   setlocale(LC_ALL, "Russian");
   cout<<"Определение простоты числа"<<endl<<"Введите число: ";
   int n; // Проверяемое число
   cin>>n;
   if (n<1)
   {
      cout<<"Число "<<n<<" не является натуральным"<<endl;
      return 0;
   }
   if (n==1)
   {
      cout<<"1 не является ни простым числом, ни составным"<<endl;
      return 0;
   }
   bool isPrime=true;
   // Цикл с пустым телом (!!!)
   for (int i=2; i<=n/2 && (isPrime=(n%i > 0)); i++);
   if (isPrime)
      cout<<"Число "<<n<<" простое"<<endl;
   else
      cout<<"Число "<<n<<" составное"<<endl;
   return 0;
}
