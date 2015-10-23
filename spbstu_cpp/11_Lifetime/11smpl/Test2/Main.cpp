#include <iostream>
using namespace std;
int main(void)
{
   char str[]="Hello world!";
   char* ptr=str;
   while (*++ptr!=' ');
   char* ptr2=str;
   for (int i=0; i<5; i++)
   {
      char temp=*++ptr;
      *ptr=*ptr2;
      *ptr2++=temp;
   }
   cout<<str<<endl;
}