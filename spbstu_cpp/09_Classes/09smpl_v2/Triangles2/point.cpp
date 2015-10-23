#include "point.h"
#include <math.h>

Point::Point() 
{
   x=y=0.0;
}

double Point::calcDistance(const Point& p) const
{
	return sqrt((p.x-x)*(p.x-x)+(p.y-y)*(p.y-y));
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

