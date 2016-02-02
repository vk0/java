#include <stdio.h>
#include <limits.h>
int main() {
printf("short int… \tsize: %d bytes %d байт \t", sizeof(short int));
printf("от %d до %d \n", SHRT_MAX, SHRT_MIN);
printf("long int… \tsize: %d bytes %d байт \t", sizeof(long int));
printf("от %d до %d \n", LONG_MAX, LONG_MIN);
printf("char… \tsize: %d bytes %d байт \n", sizeof(char));
printf("float… \tsize: %d bytes %d байт \n", sizeof(float));
printf("double… \tsize: %d bytes %d байт \n", sizeof(double));
return 0;
}