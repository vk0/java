#include <iostream>
using namespace std;
int main(void)
{
   int d=0x12345678;
   char* ptr=(char*)&d;
   for (int i=0; i<4; i++, ptr++)
      cout<<hex<<(int)ptr<<'\t'<<(int)*ptr<<endl;
   return 0;
}