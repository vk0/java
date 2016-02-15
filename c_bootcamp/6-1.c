// 1 Below is a program that uses a struct to encapsulate a two dimensional matrix. The struct contains the matrix values, and the dimensions of the matrix. We assume that the matrix is filled row by row (that is, across columns). Since we haven't covered dynamic allocation of memory yet, for now we assume a matrix can hold a maximum number of values equal to 1024. We will cover dynamic allocation of memory later.

// Your first task is to write a function that prints a matrix to the screen. A function skeleton is provided (printmat()).
// 2 Your next task is to write a function that performs matrix multiplication. A function skeleton is provided (matrixmult()).

// gcc -Wall -o go 6_1_go.c

#include <stdio.h>

#define MAXDATA 1024

typedef struct {
    double data[MAXDATA];
    int nrows;
    int ncols;
} Matrix;

void printmat(Matrix M);
Matrix matrixmult(Matrix A, Matrix B);

int main(int argc, char *argv[])
{
    Matrix A = { {
            1.2, 2.3,
            3.4, 4.5,
            5.6, 6.7
        },
        3,
        2
    };
    Matrix B = { {
            5.5, 6.6, 7.7,
            1.2, 2.1, 3.3
        },
        2,
        3
    };
    printmat(A);
    printmat(B);

    //  Matrix C = matrixmult(A, B);
    //  printmat(C);

    return 0;
}

// your code goes below...

void printmat(Matrix M)
{
    int i, j;
    printf("[\n");
    for (i = 0; i < M.nrows; i++) {
        for (j = 0; j < M.ncols; j++) {
            printf("%6.3f ", M.data[i * M.ncols + j]);
        }
        printf("\n");
    }
    printf("]\n\n");
}

Matrix matrixmult(Matrix A, Matrix B)
{
    Matrix C;
    if (A.ncols != B.nrows) {
        printf("error: ncols of A does not equal nrows of B\n");
    }
    else {
        int i, j, k;
        double count;
        for (i = 0; i < A.nrows; i++) {
            for (j = 0; j < B.ncols; j++) {
                count = 0.0;
                for (k = 0; k < A.ncols; k++) {
                    count += A.data[i * A.ncols + k] * B.data[k * B.ncols + j];
                }
                C.data[i * A.nrows + j] = count;
            }
        }
        C.nrows = A.nrows;
        C.ncols = B.ncols;
    }
    return C;
}