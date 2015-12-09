// Основый препроцессорной обработки

// Примеры использования #define

#define SIZE 100
#define PRINT_X printf("X:\t%7d\n",x)
#define CUBE(N) ((N)*(N)*(N))

int a[SIZE]; // = int a[100]
PRINT_X; // = printf("X:\t%7d\n",x)
printf("%d\n", CUBE(SIZE)); // = printf("%d\n",((100)*(100)*(100)))

// Примеры использования условной компиляуии и #error

#ifdef ANSI_C_LIKE
#define A 110341231
#else
#define A 123123123
#endif

#ifndef __cplusplus
#error A C++ compler is required!
#endif

// Примеры использования #pragma

File "grandfather.h"
#pragma once // это файл гарантированое будет подключен только один раз

File "father.h"
#include "grandfather.h"

File "child.c"
#include "grandfather.h"
#include "father.h"