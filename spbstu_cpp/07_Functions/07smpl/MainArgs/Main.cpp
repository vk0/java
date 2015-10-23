#include <iostream>
#include <locale.h>
using namespace std;
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	if (argc < 3)
	{
		cout<<"Строка запуска: MainArgs.exe infile outfile"<<endl;
		return -1;
	}
	cout<<"Входной файл: "<<argv[1]<<endl;
	cout<<"Выходной файл: "<<argv[2]<<endl;
	return 0;
}