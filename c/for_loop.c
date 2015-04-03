#include <stdio.h>

main() {

unsigned char a;
for (a = 31; a < 128; a++) {
if (a % 10 == 0)
printf("\n");
printf("%4d-%c", a, a);
}
printf("\n");

}
