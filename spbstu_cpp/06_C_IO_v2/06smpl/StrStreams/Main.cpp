#include <iostream>
#include <strstream>
#include <string.h>
using namespace std;
int main(void)
{
   ostrstream out;
   int a=2, b=3;
   out<<a+b<<"="<<a<<"+"<<b;
   char* str=out.str();
   char buffer[20];
   for (int i=0; i<out.pcount(); i++)
      buffer[i]=str[i];
   buffer[out.pcount()]=0;
   cout<<"Buffer: "<<buffer<<endl;
   istrstream in(buffer);
   int s=0;
   a=b=0;
   in>>s>>a>>b;
   cout<<"s="<<s<<" a="<<a<<" b="<<b<<endl;
   return 0;
}
