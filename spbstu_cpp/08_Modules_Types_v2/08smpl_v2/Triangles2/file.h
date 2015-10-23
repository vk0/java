#ifndef _FILE_H
#define _FILE_H

#include "geometry.h"

// Подсчет числа точек во входном файле
int countPoints(const char* fileName);

// Чтение точек из входного файла
bool readPoints(const char* fileName, Point* pointArray, int maxPointNum);

// Вывод треугольников в выходной файл
bool writeTriangles(const char* fileName, const Triangle* trArray, int trNum);

#endif