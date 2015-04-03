#include <stdio.h>

main() {

int a=1;

switch (a) {
    case 0:
        printf("%d\n", 0);
        break;
    case 1:
        printf("%d\n", 1);
        break;
    case 2:
        printf("%d\n", 2);
        break;
    default:
        printf("%d\n", -1);
    }

}
