// Ниже приведена программа, которая рекурсивно обходит всю файловую систему и печатает пути ко всем найденным файлам.

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
void traverse(char const *dir)
{
    char name[PATH_MAX];
    DIR *d;
    struct dirent *dd;
    off_t o;
    struct stat s;
    char *delim = "/";
    /* если в качестве каталога передан корневой каталог,
    * разделитель не нужен */
    if (!strcmp(dir, "/")) delim = "";
    /* открываем каталог */
    if (!(d = opendir(dir))) {
        /* не смогли открыть */
        perror(dir);
        return;
    }
    /* считываем, пока dd не равен NULL, то есть
    * пока есть записи в каталоге */
    while ((dd = readdir(d))) {
        /* пропускаем . и .. */
        if (!strcmp(dd->d_name, ".") || !strcmp(dd->d_name, ".."))
            continue;
        /* формируем полный путь */
        snprintf(name, PATH_MAX, "%s%s%s", dir, delim, dd->d_name);
        /* получаем информацию о файле
        * используем lstat, чтобы не зациклиться на символических
        * связях */
        if (lstat(name, &s) < 0) continue;
        /* проверяем, что это каталог */
        if (S_ISDIR(s.st_mode)) {
            /* запоминаем текущее положение в каталоге */
            o = telldir(d);
            /* экономим файловые дескрипторы */
            closedir(d);
            /* вызываем себя рекурсивно */
            traverse(name);
            /* восстанавливаем старое положение */
            if (!(d = opendir(dir))) {
                perror(dir);
                return;
            }
            seekdir(d, o);
        } else {
            /* печатаем путь */
            printf("%s\n", name);
        }
    }
    closedir(d);
}
int main(void)
{
    traverse("/");
    return 0;
}
