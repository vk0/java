#include <iostream>
using namespace std;

void f1(int a)
{
	static int sum = 0;
	sum += a;
	cout<<"a="<<a<<" sum="<<sum<<endl;
	for (static int j=0; j<a; j++)
	{
		cout<<"j="<<j<<endl;
	}
}

int main(void)
{
	int a;
	cin>>a;
	for (int i=1; i<=a; i++)
		f1(i);
	return 0;
}