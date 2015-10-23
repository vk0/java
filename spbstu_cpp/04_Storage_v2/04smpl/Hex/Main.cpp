#include <iostream>
using namespace std;
int main(void)
{
	int hexNumber = 0xa96d;
	cout<<hex<<hexNumber<<"[16]="<<dec<<hexNumber<<"[10]"<<endl;
	cout<<hex<<0.23<<endl;
	int maxInt = 0x7fffffff;
	cout<<dec<<maxInt+1<<endl;
	return 0;
}