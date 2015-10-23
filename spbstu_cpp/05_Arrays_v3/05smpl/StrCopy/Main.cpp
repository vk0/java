#include <iostream>
using namespace std;
int main(void)
{
   char src[] = "Some string";
   char dst[20];
   // Копирование через индексацию
   int i;
   for (i=0; src[i]!=0; i++)
      dst[i]=src[i];
   dst[i]=0;
   cout<<dst<<endl;
   // Копирование через указатели I
   const char* psrc=src; // Константный указатель
   char* pdst=dst;
   while (*psrc)
      *pdst++ = *psrc++;
   *pdst = 0;
   cout<<dst<<endl;
   // Копирование через указатели II
   psrc=src;
   pdst=dst;
   while (*pdst++ = *psrc++);
   cout<<dst<<endl;
   return 0;
}
