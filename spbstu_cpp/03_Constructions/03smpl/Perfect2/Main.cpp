#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

bool isPerfect(int n)
{
    int sum=1; // Сумма делителей
    for (int j=2; j<=n/2; j++)
    {
        if (n%j == 0)
        {
            sum += j;
            // Чтобы не тратить зря время
            if (sum > n)
                return false;
        }
    }
    return sum == n;
}

void printPerfect(int n)
{
    cout<<n<<"=1+"; int sum=1;
    for (int j=2; j<=n/2; j++)
        if (n%j == 0)
        {
            cout<<j;
            sum += j;
            if (sum == n) // Если последний делитель найден
            {
                cout<<endl;
                return;
            }
            else cout<<"+"; // Делитель не последний
        }
}


int main(void)
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout<<"Поиск совершенных чисел. Введите максимум: ";
	cin>>n;
	if (n<6)
	{
		cout<<"Совершенных чисел не найдено"<<endl;
		return 0;
	}
	for (int i=6; i<=n; i++) // Числа
	{
		if (isPerfect(i))
			printPerfect(i);
	}
	return 0;
}

