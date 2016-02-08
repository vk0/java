// Задача на зомби.

// Создайте два процесса - родитель и потомок (сохраните их PIDы в /home/box/pid_parent и /home/box/pid_child).

// Потомок должен убиваться по SIGTERM. При убийстве потомка не должно остаться процессов-зомби.

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    pid_t chpid = fork();

    if (! chpid) {
        for (;;) usleep(5000);
        return 0;
    }

    pid_t pid = getpid();
    printf("parent pid: %d\n", pid);

//#define FPID ("/home/box/pid")
#define PPID ("./pid_parent")
#define CPID ("./pid_child")
    FILE *f1 = fopen(PPID, "w");
    FILE *f2 = fopen(CPID, "w");
    if (NULL == f1 || NULL == f2) {
        perror("fopen");
        return (1);
    }
    int rc = fprintf(f1, "%d\0", pid);
    fprintf(f2, "%d\0", chpid);
    fflush(f1); fflush(f2);
    printf("%d\n", rc);

    waitpid(chpid, &rc, 0);
    printf("child process killed: %d\n", rc);
    for (;;) usleep(5000);

    fclose(f1); fclose(f2);
    return 0;
}
