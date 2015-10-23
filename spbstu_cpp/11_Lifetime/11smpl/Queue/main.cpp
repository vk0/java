#include <iostream>
#include "queue.h"
using namespace std;

int main(void)
{
   putInteger(7);
   putInteger(10);
   putInteger(8);
   int num;
   while (getInteger(&num))
      cout<<"Number got: "<<num<<endl;
   return 0;
}