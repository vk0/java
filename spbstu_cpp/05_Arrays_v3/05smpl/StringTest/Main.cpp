#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
	setlocale(LC_ALL, "Russian");
	char c[5];
	for (int i=0; i<5; i++)
		cin>>c[i];
	for (int i=0; i<5; i++)
		cout<<"Символ "<<i<<":"<<c[i]<<endl;
	cin>>noskipws;
	for (int i=0; i<5; i++)
		cin>>c[i];
	for (int i=0; i<5; i++)
		cout<<"Символ "<<i<<":"<<c[i]<<endl;
	return 0;
}