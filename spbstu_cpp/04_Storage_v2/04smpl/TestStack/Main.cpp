#include <iostream>
using namespace std;

const int size=0x10000000;
int arr[size];

int main(void)
{
   for (int i=0; i<size; i++)
      arr[i]=i;
   int sum = 0;
   for (int i=0; i<size; i++)
      sum += arr[i];
   cout<<sum<<endl;
   return 0;
}