#include <iostream>
using namespace std;
static int i;
static void myFunc(int a)
{
	cout<<a;
}

int main(void)
{
   int length;
   cin>>length; 
   int sum=0;
   for (int i=0; i<length; i++)
      sum += (i/3)*3; 
   sum = sum*length; 
   cout<<"sum="<<sum<<endl;
   return 0;
}
