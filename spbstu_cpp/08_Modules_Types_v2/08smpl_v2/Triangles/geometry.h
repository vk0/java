#ifndef _GEOMETRY_H
#define _GEOMETRY_H

// Расстояние между двумя точками по их координатам
double calcDistance(double xa, double ya, double xb, double yb);

// Площадь треугольника по координатам точек
double calcAreaByPoints(double xa, double ya, double xb, double yb, double xc, double yc);

#endif