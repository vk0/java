#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main(void)
{
   char str[]="5=2+3";
   int a,b,s;
   sscanf(str,"%d=%d+%d",&s,&a,&b);
   printf("s=%d a=%d b=%d\n",s,a,b);
   return 0;
}