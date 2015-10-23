#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "point.h"
#include <iostream>
using namespace std;

struct Triangle
{
   Point vertexes[3];
   double area;
   // Очистка
   Triangle();
   // Расчет площади
   double calcArea();
   // Сравнение площадей
   bool operator <=(const Triangle& tr) const;
   // Вывод треугольника
   friend ostream& operator <<(ostream& out, const Triangle& tr);
};

#endif