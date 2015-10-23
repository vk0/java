#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
   int min=2, max=1000;
   setlocale(LC_ALL, "Russian");
   for (int n=min; n<=max; n++)
   {
      bool isPrime=true;
      for (int i=2; i<=n/2 && (isPrime=(n%i > 0)); i++);
      if (isPrime)
         cout<<"Число "<<n<<" простое"<<endl;
   }
   return 0;
}