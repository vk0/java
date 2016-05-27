// Напишем реализацию функции system (стандартная функция, которая выполняет заданную команду).

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int system(char const *cmd)
{
    int pid, status;
    if ((pid = fork()) < 0) {
        /* ошибка */
        perror("fork");
        return -1;
    } else if (!pid) {
        /* child */
        execl("/bin/sh", "/bin/sh", "-c", cmd, NULL);
        /* ошибка */
        perror("execl");
        _exit(1);
    }
    /* parent */
    wait(&status);
    if (WIFSIGNALED(status)) return WTERMSIG(status) + 256;
    return WEXITSTATUS(status);
}