#ifndef _FILE_H
#define _FILE_H

// Подсчет числа точек во входном файле
int countPoints(const char* fileName);

// Чтение точек из входного файла
bool readPoints(const char* fileName, double* px, double* py, int maxPointNum);

// Вывод треугольников в выходной файл
bool writeTriangles(const char* fileName, const double tx[][3], const double ty[][3], int trNum);

#endif