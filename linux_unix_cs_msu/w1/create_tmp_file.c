// Следующая программа иллюстрирует работу со временными файлами.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
/* если P_tmpdir неопределён, установим его в /tmp */
#ifndef P_tmpdir
#define P_tmpdir "/tmp"
#endif
int main(void)
{
    char tmpn[PATH_MAX];
    char *s;
    int fd;
    FILE *f;
    int a, b, c;
    /* если переменная окружения TMPDIR установлена,
    * используем её, иначе - P_tmpdir */
    if (!(s = getenv("TMPDIR"))) s = P_tmpdir;
    /* формируем шаблон */
    snprintf(tmpn, PATH_MAX, "%s/progXXXXXX", s);
    /* создаём временный файл */
    if ((fd = mkstemp(tmpn)) < 0) {
        perror("mkstemp");
        return 1;
    }
    /* удаляем его */
    unlink(tmpn);
    /* формируем дескриптор потока */
    if (!(f = fdopen(fd, "r+"))) {
        perror("fdopen");
        return 1;
    }
    /* запишем в него что-нибудь */
    fprintf(f, "%d %d %d\n", 1, 1, 2001);
    /* ... */
    /* f нельзя закрывать!
    * устанавливаемся на начало файла для чтения */
    fseek(f, 0, SEEK_SET);
    /* читаем данные */
    if (fscanf(f, "%d%d%d", &a, &b, &c) != 3) {
        fprintf(stderr, "temporary file error\n");
        return 1;
    }
    printf("Read values: %d %d %d\n", a, b, c);
    /* временный файл больше не нужен, закрываем его */
    fclose(f);
    return 0;
}
