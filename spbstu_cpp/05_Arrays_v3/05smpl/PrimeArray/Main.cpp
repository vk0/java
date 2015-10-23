#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
	ofstream out("prime.txt"); // Файл для вывода
	const int PRIME_NUM = 300000; // Всего нужно найти
	int primeFound = 0; // Уже найдено
	int primeArray[PRIME_NUM]; // Массив простых чисел
	int current = 2; // Текущее проверяемое число
	int limit = 1; // Последний проверяемых делитель
	while (primeFound < PRIME_NUM) // Пока не нашли все числа
	{
		bool isPrime = true; // Признак простоты
		if ((limit+1)*(limit+1)<=current)
			limit++; 
		for (int i=0; i<primeFound && primeArray[i]<=limit; i++)
			if (current%primeArray[i]==0)
			{
				// Если разделилось то не простое			
				isPrime = false;
				break;
			}
		if (isPrime)
		{
			out<<current<<endl; // Вывод
			primeArray[primeFound++]=current; // Сохранить и увелич. индекс
		}
		current++;
	}
	return 0;
}