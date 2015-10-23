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
	double x,y;
	int i;
	for (i=0; ; i++) 
	{
		in>>x>>y;
		if (in.fail())
			break;
	} 
	return i;
}

bool readPoints(const char* fileName, double* px, double* py, int maxPointNum)
{
	ifstream in(fileName);
	// Файл не открыт
	if (!in.is_open())
		return 0;
	for (int i=0; i<maxPointNum; i++)
	{
		in>>px[i]>>py[i];
		if (in.fail())
			return false;
	}
	return true;
}

bool writeTriangles(const char* fileName, const double tx[][3], const double ty[][3], int trNum)
{
	ofstream out(fileName);
	if (!out.is_open())
		return false;
	for (int i=0; i<trNum; i++)
	{
		out<<"#"<<i+1<<
			": A=("<<tx[i][0]<<","<<ty[i][0]<<
			") B=("<<tx[i][1]<<","<<ty[i][1]<<
			") C=("<<tx[i][2]<<","<<ty[i][2]<<
			") S="<<calcAreaByPoints(tx[i][0],ty[i][0],tx[i][1],ty[i][1],tx[i][2],ty[i][2])<<endl;
	}
	return true;
}