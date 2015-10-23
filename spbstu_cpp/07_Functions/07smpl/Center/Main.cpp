#include <iostream>
#include <fstream>
#include <locale.h>
#include <string.h>
using namespace std;

// Глобальная константа - макс. длина строки
const int STR_LENGTH = 80;

// Функция чтения очередной строки из файла
// in - ссылка на поток, соответствующий файлу
// buffer - массив, куда следует записать результат
// результат - истина, если строка прочитана успешно
bool readLine(ifstream& in, char* buffer)
{
	buffer[0] = 0;
	in.getline(buffer, STR_LENGTH+1, '\n');
	if (in.fail())
	{
		if (buffer[0]>0)
			cout<<"Слишком длинная строка во входном файле"<<endl;
		return false;
	}
	return true;
}

// Функция центрирования строки
// buffer - массив со строкой, которую центрируем
void centerLine(char* buffer)
{
	// Длина строки
	int len=strlen(buffer);
	// На сколько сдвигаем
	int shift = (STR_LENGTH-len)/2;
	if (shift==0)
		return;
	// Сдвинуть len символов + нуль-символ
	// Начиная с последнего! (почему?)
	for (int i=len; i>=0; i--)
		buffer[i+shift]=buffer[i];
	for (int i=0; i<shift; i++)
		buffer[i]=' ';
	return;
}

int main(void)
{
	setlocale(LC_ALL,"Russian");
	ifstream in("in.txt");
	if (!in.is_open())
	{
		cout<<"Файл in.txt не существует"<<endl;
		return -1;
	}
	ofstream out("out.txt");
	if (!out.is_open())
	{
		cout<<"Невозможно создать выходной файл out.txt"<<endl;
		return -2;
	}
	char buffer[STR_LENGTH+1];
	while(readLine(in, buffer))
	{
		centerLine(buffer);
		out<<buffer<<endl;
	}
	cout<<"Программа успешно завершена!"<<endl;
	return 0;
}
				
	

