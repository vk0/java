// Следующий пример копирует содержимое заданного файла на стандартный вывод.

#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *f;
    char buf[256];
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments\n");
        return 1;
    }
    if (!(f = fopen(argv[1], "r"))) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        return 1;
    }
    while (fgets(buf, sizeof(buf), f))
        fputs(buf, stdout);
    fclose(f);
    return 0;
}
