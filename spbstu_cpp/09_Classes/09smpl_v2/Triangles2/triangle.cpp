#include "triangle.h"
#include <math.h>

Triangle::Triangle() 
{
   area=0.0;
}

static double calcAreaBySides(double a, double b, double c)
{
	double p2=(a+b+c)/2.0;
   // Ќе забываем проверить, что корень извлечетс€
	if (p2<=0.0 || p2<=a || p2<=b || p2<=c)
		return 0.0;
	return sqrt(p2*(p2-a)*(p2-b)*(p2-c));
}

double Triangle::calcArea()
{
	double a=vertexes[0].calcDistance(vertexes[1]);
	double b=vertexes[1].calcDistance(vertexes[2]);
	double c=vertexes[2].calcDistance(vertexes[0]);
	return area=calcAreaBySides(a, b, c);
}

ostream& operator <<(ostream& out, const Triangle& tr)
{
   out<<"A="<<tr.vertexes[0]<<" B="<<tr.vertexes[1]<<
       " C="<<tr.vertexes[2]<<" area="<<tr.area;
   return out;
}

bool Triangle::operator <=(const Triangle& tr) const
{
   return area <= tr.area;
}
