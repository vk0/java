#include <iostream>
#include <locale.h>
using namespace std;
int main(void)
{
	int m, n; // цифра и число
	setlocale(LC_ALL, "Russian");
	cout<<"Поиск цифры в числе"<<endl;
	cout<<"Введите цифру и число >0, через пробел: ";
	cin>>m>>n;
	if (m<0 || m>9 || n<0)
	{
		cout<<"Некорректные данные"<<endl;
		return 0;
	}
	int found=0; // Сколько уже найдено цифр
	do
	{
		int d=n%10; // Очередная цифра
		if (d==m)
			found++;
		n/=10;
	} while (n>0);
	cout<<"Всего найдено "<<found<<" цифр"<<endl;
	return 0;
}
