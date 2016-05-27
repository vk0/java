// Напишем программу, которая печатает все процессы, идентификатор пользователя ко-
// торых 0 (root). Для получения списка процессов будем использовать вызов программы ps.
// Предположим, что второе число в строке, печатаемой командой ps как раз содержит иден-
// тификатор пользователя.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
void pexit(char const *str)
{
    perror(str);
    exit(1);
}
int main(void)
{
    char tmppatt[] = "/tmp/XXXXXX";
    int fd, pid, status;
    FILE *f;
    char buf[1024];
    int v1, v2;
    /* создаём временный файл */
    if ((fd = mkstemp(tmppatt)) < 0) pexit("mkstemp");
    /* сразу удаляем */
    if (unlink(tmppatt) < 0) pexit("unlink");
    /* создаём новый процесс */
    if ((pid = fork()) < 0) pexit("fork");
    if (!pid) { /* сын */
        /* перенаправляем стандартный вывод */
        if (dup2(fd, 1) != 1) { perror("dup2"); _exit(1); }
        /* закрываем старый дескриптор */
        close(fd);
        /* вызываем другой процесс */
        execlp("ps", "ps", "axl", 0);
        perror("execlp");
        _exit(1);
    }
    /* отец */
    /* ждём */
    wait(&status);
    /* ошибка выполнения сыновнего процесса */
    if (!WIFEXITED(status) || WEXITSTATUS(status) > 0) exit(1);
    /* перематываем файл на начало */
    if (lseek(fd, 0, SEEK_SET) < 0) pexit("lseek");
    /* связываем уже открытый файловый дескриптор с FILE * */
    if (!(f = fdopen(fd, "r"))) pexit("fdopen");
    while (fgets(buf, sizeof(buf), f)) {
        if (strlen(buf) >= sizeof(buf) - 1) {
            fprintf(stderr, "string too long\n");
            exit(1);
        }
        /* печатаем все процессы, владелец которых - root */
        if (sscanf(buf, "%d %d", &v1, &v2) == 2 && !v2)
            printf("%s", buf);
    }
    fclose(f);
    return 0;
}