#include "file.h"
#include "search.h"
#include <iostream>
#include <locale.h>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	if (argc < 3)
	{
		cout<<"Строка запуска: Triangles.exe infile.txt outfile.txt"<<endl;
		return -1;
	}
	const char* inFileName = argv[1];  // Имя входного файла
	const char* outFileName = argv[2]; // Имя выходного файла
	int pointNum = countPoints(inFileName);
	if (pointNum < 4)
	{
		cout<<"Входной файл не существует или в нем слишком мало точек"<<endl;
		return -2;
	}
   Point* pointArray = new Point[pointNum];
	if (!readPoints(inFileName, pointArray, pointNum))
	{
		cout<<"Неизвестная ошибка при вводе точек из файла"<<endl;
		return -3;
	}
	const int maxTrNum = 3;
   Triangle trArray[maxTrNum];
	searchLargestTriangles(pointArray, pointNum, trArray, maxTrNum);
	if (!writeTriangles(outFileName, trArray, maxTrNum))
	{
		cout<<"Не удалось записать результат в выходной файл"<<endl;
		return -4;
	}
	cout<<"Программа успешно завершена"<<endl;
   delete[] pointArray;
	return 0;
}