#include "search.h"
#include "geometry.h"

// Вставить в массив trArray, упорядоченный по убыванию площади,
// новый треугольник triangle
void findAndInsert(Triangle* trArray, int length, const Triangle& triangle)
{
   int pos;
   for (pos=length-1; pos>=0; pos--)
   {
      if (triangle <= trArray[pos])
         break;
   }
   pos++;
   if (pos==length)
      return;
   for (int m=length-2; m>=pos; m--)
      trArray[m+1]=trArray[m];
   trArray[pos]=triangle;
}

void searchLargestTriangles(const Point* pointArray, int pointNum,
                            Triangle* trArray, int maxTrNum)
{
   if (maxTrNum <= 0)
      return;
   for (int i=0; i<maxTrNum; i++)
      clearTriangle(trArray[i]);
   // Перебор троек точек
   Triangle triangle;
   for (int i=0; i<pointNum; i++)
   {
      triangle.vertexes[0] = pointArray[i];
      for (int j=i+1; j<pointNum; j++)
      {
         triangle.vertexes[1] = pointArray[j];
         for (int k=j+1; k<pointNum; k++)
         {
            triangle.vertexes[2] = pointArray[k];
            calcTriangleArea(triangle);
            findAndInsert(trArray, maxTrNum, triangle);
         }
      }
   }
}