#include "geometry.h"
#include <math.h>

double calcDistance(double xa, double ya, double xb, double yb)
{
	return sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
}

double calcAreaBySides(double a, double b, double c)
{
	double p2=(a+b+c)/2.0;
   // Ќе забываем проверить, что корень извлечетс€
	if (p2<=0.0 || p2<=a || p2<=b || p2<=c)
		return 0.0;
	return sqrt(p2*(p2-a)*(p2-b)*(p2-c));
}

double calcAreaByPoints(double xa, double ya, double xb, double yb, double xc, double yc)
{
	double ab=calcDistance(xa, ya, xb, yb);
	double bc=calcDistance(xb, yb, xc, yc);
	double ca=calcDistance(xc, yc, xa, ya);
	return calcAreaBySides(ab, bc, ca);
}