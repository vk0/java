#include "file.h"
#include "geometry.h"
#include <fstream>
using namespace std;

int countPoints(const char* fileName)
{
	ifstream in(fileName);
	// Файл не открыт
	if (!in.is_open())
		return 0;
	Point p;
	int i;
	for (i=0; ; i++)
	{
		in>>p;
		if (in.fail())
			break;
	}
	return i;
}

bool readPoints(const char* fileName, Point* pointArray, int maxPointNum)
{
	ifstream in(fileName);
	// Файл не открыт
	if (!in.is_open())
		return 0;
	for (int i=0; i<maxPointNum; i++)
	{
		in>>pointArray[i];
		if (in.fail())
			return false;
	}
	return true;
}

bool writeTriangles(const char* fileName, const Triangle* trArray, int trNum)
{
   ofstream out(fileName);
   if (!out.is_open())
      return false;
   for (int i=0; i<trNum; i++)
      out<<"#"<<i+1<<": "<<trArray[i]<<endl;
   return true;
}