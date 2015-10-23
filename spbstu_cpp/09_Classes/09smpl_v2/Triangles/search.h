#ifndef _SEARCH_H
#define _SEARCH_H

#include "geometry.h"

// Поиск треугольников максимальной площади
void searchLargestTriangles(const Point* pointArray, int pointNum,
                            Triangle* trArray, int maxTrNum);

#endif