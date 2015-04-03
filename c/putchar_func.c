#include <stdio.h>

main() {

char str[] = "Hello";
int i;
printf("%s\n", str); // первое Hello

for (i = 0; str[i] != '\0'; i++) // второе Hello
    putchar(str[i]);
    printf("\n");

}
