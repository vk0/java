#include <iostream>
using namespace std;
int main(void)
{
   int arr[][2] = { {1, 2}, {3, 4}, {5, 6} };
   cout<<*(arr+1)<<endl;
   cout<<arr[1]<<endl;
//   int* ptr = arr;
//   cout<<*(ptr+1)<<endl;
   int d=2;
   int myarr[d];
   return 0;
}