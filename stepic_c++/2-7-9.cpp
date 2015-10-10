// Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный массив) размера rows×cols, и возвращает транспонированную матрицу MT (тоже двумерный целочисленный массив) размера cols×rows. Если в M на пересечении i-ой строки и j-ого столбца стояло число x, то на пересечении  j-ой строки и i-ого столбца в матрице MT тоже будет стоять число x, или другими словами MT[j][i]=M[i][j].

// Обратите внимание, что вам неизвестно, каким именно способом выделялась память для массива M. Выделять память под массив MT можете любым удобным вам способом. Изменять исходную матрицу нельзя.

// Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. Вводить или выводить что-либо не нужно. Реализовывать функцию main не нужно.

#include <iostream>
using namespace std;

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** mt = new int *[cols];
    mt[0]=new int [cols*rows];
    for (int i=1;i!=cols;i++){
        mt[i]=mt[i-1]+rows;
    }

    for (int i=0;i!=cols;i++){
        for (int j=0; j!=rows; j++) {
            mt[i][j]=m[j][i];
        }
    }

    return mt;
    /* ... */
}

int main(int argc, const char * argv[]) {

    int rows=2;
    int cols=3;

    int ** m = new int *[2];
    m[0]=new int [6];
    for (int i=1;i!=2;i++){
        m[i]=m[i-1]+3;
    }

    int k=0;
    for (int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            k++;
            m[i][j]=k;
        }
    }

    for (int i=0;i<2;i++){
        for (int j=0; j<3; j++) {
            cout<<m[i][j]<<' ';
        }
        cout<<endl;
    }

    cout<<endl;

    int ** a=0;
    a=transpose(m, 2, 3);

    for (int i=0;i<cols;i++){
        for (int j=0; j<rows; j++) {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }


    return 0;
}