#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
   setlocale(LC_ALL, "Russian");
   cout<<"Определение простоты числа"<<endl<<"Введите число: ";
   int i, n; // Проверяемое число и счетчик цикла
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

   for (i=2; i<n; i++)
   {
      if (n%i==0)
         break;
   }
   // Если цикл завершился без помощи break, i будет равно n
   // В противном случае i будет меньше
   if (i<n)
      cout<<"Число "<<n<<" составное"<<endl;
   else
      cout<<"Число "<<n<<" простое"<<endl;
   return 0;
}
