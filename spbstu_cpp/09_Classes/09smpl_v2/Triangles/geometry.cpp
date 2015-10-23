#include "geometry.h"
#include <math.h>

void clearPoint(Point& p)
{
   p.x=p.y=0.0;
}

void clearTriangle(Triangle& tr)
{
   for (int i=0; i<3; i++)
      clearPoint(tr.vertexes[i]);
   tr.area=0.0;
}

double calcDistance(const Point& pa, const Point& pb)
{
	return sqrt((pb.x-pa.x)*(pb.x-pa.x)+(pb.y-pa.y)*(pb.y-pa.y));
}

double calcAreaBySides(double a, double b, double c)
{
	double p2=(a+b+c)/2.0;
   // Ќе забываем проверить, что корень извлечетс€
	if (p2<=0.0 || p2<=a || p2<=b || p2<=c)
		return 0.0;
	return sqrt(p2*(p2-a)*(p2-b)*(p2-c));
}

double calcTriangleArea(Triangle& tr)
{
	Point* v = tr.vertexes;
	double a=calcDistance(v[0], v[1]);
	double b=calcDistance(v[1], v[2]);
	double c=calcDistance(v[2], v[0]);
	return tr.area=calcAreaBySides(a, b, c);
}

istream& operator >>(istream& in, Point& p)
{
   in>>p.x>>p.y;
   return in;
}

ostream& operator <<(ostream& out, const Point& p)
{
   out<<"("<<p.x<<" "<<p.y<<")";
   return out;
}

ostream& operator <<(ostream& out, const Triangle& tr)
{
   out<<"A="<<tr.vertexes[0]<<" B="<<tr.vertexes[1]<<
       " C="<<tr.vertexes[2]<<" area="<<tr.area;
   return out;
}

bool operator <=(const Triangle& tr1, const Triangle& tr2)
{
   return tr1.area <= tr2.area;
}
