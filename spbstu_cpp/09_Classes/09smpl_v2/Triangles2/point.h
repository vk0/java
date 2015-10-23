#ifndef _POINT_H
#define _POINT_H

#include <iostream>
using namespace std;

struct Point
{
private:
   double x, y;
public:
   Point();
   // Расстояние между двумя точками по их координатам
   double calcDistance(const Point& p) const;
   // Ввод точки
   friend istream& operator >>(istream& in, Point& p);
   // Вывод точки
   friend ostream& operator <<(ostream& out, const Point& p);
};

#endif
