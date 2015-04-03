#include <stdio.h>

main() {

int a = 5, b = 7;
float c = 6.98;
int *pa, *pb;
float *pc;
pa = pb = NULL;
pc = NULL;
printf(" %15p %15p %15p\n", pa, pc, pb);
pa = &a;
pb = &b;
pc = &c;
printf(" %15p %15p %15p\n", pa, pc, pb);
printf(" %15d %15f %15d\n", *pa, *pc, *pb);

}
