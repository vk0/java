#ifndef _GEOMETRY_H
#define _GEOMETRY_H

#include <iostream>
using namespace std;

struct Point
{
   double x, y;
};

struct Triangle
{
   Point vertexes[3];
   double area;
};

void clearPoint(Point& p);

void clearTriangle(Triangle& tr);

// Расстояние между двумя точками по их координатам
double calcDistance(const Point& pa, const Point& pb);

// Площадь треугольника по координатам точек
double calcTriangleArea(Triangle& tr);

// Ввод точки
istream& operator >>(istream& in, Point& p);

// Вывод точки
ostream& operator <<(ostream& out, const Point& p);

// Вывод треугольника
ostream& operator <<(ostream& out, const Triangle& tr);

// Сравнение треугольников
bool operator <=(const Triangle& tr1, const Triangle& tr2);

#endif