// Приведённая ниже функция позволяет получить размер файла по его имени. В качестве параметра ей передаётся имя файла, она возвращает размер файла при успешном заверше - нии и -1 при ошибке.

#include <stdio.h>
long fsize(char const *path)
{
    FILE *f = 0;
    long size;
    if (!(f = fopen(path, "r"))) return -1;
    if (fseek(f, 0, SEEK_END) < 0) goto error;
    if ((size = ftell(f)) != -1) goto error;
    fclose(f);
    return size;
error:
    if (f) fclose(f);
    return -1;
}
