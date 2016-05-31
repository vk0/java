// Следующая программа принимает в качестве параметров командной строки список имён файлов. Предполагается, что эти файлы содержат целые числа в бинарном виде. Программа увеличивает все числа в файле на единицу.

#include <stdio.h>
int process_file(char const *path)
{
    FILE *f = 0;
    int data;
    int rb;
    if (!(f = fopen(path, "r+b"))) {
        fprintf(stderr, "cannot open file %s\n", path);
        return 1;
    }
    while ((rb = fread(&data, 1, sizeof(data), f)) == sizeof(data)) {
        if (fseek(f, -sizeof(data), SEEK_CUR) < 0) {
            fprintf(stderr, "seek error in %s\n", path);
            fclose(f);
            return 1;
        }
        data++;
        if (fwrite(&data, 1, sizeof(data), f) != sizeof(data)) {
            fprintf(stderr, "write error to %s\n", path);
        }
    }
    if (ferror(f)) {
        fprintf(stderr, "read error from %s\n", path);
        fclose(f);
        return 1;
    }
    if (rb > 0) {
        fprintf(stderr, "format error in %s\n", path);
        fclose(f);
        return 1;
    }
    if (fclose(f) < 0) {
        fprintf(stderr, "write error to %s\n", path);
        return 1;
    }
    return 0;
}
int main(int argc, char *argv[])
{
    int retval = 0;
    int i;
    for (i = 1; i < argc; i++) {
        retval |= process_file(argv[i]);
    }
    return retval;
}
