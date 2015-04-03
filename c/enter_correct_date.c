#include <stdio.h>
main () {
int a, n;
float b;
char str[20];

    do {
        printf("Enter a integer, a float, a string: ");
        n = scanf("%d%f%s", &a, &b, str);
        if (n != 3) {
            scanf("%*s%*s%*s");
        }
    } while (n != 3);
        printf("Integer: %d, float: %.3f, string: %s\n", a, b, str);
}
