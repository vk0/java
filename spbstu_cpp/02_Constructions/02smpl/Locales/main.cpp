#include <locale.h>
#include <iostream>

using namespace std;

int main(void)
{
	cout<<"Здравствуй, мир!"<<endl;
	setlocale(LC_ALL, "Russian");
	cout<<"Здравствуй, мир!"<<endl;
	return 0;		
}