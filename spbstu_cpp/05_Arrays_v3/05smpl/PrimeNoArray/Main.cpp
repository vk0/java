#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
   ofstream out("prime.txt");
   const int PRIME_NUM = 200000;
   int primeFound = 0;
   int limit = 1;
   for (int current=2; ; current++)
   {
      bool isPrime=true;
      if ((limit+1)*(limit+1) <= current)
         limit++;
      for (int i=2; i<=limit && (isPrime=(current%i > 0)); i++);
      if (isPrime)
      {
         out<<current<<endl;
	 primeFound++;
	 if (primeFound >= PRIME_NUM)
	    break;
      }
   }
   return 0;
}