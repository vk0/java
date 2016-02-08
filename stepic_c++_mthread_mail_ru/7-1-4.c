// Напишите многопоточную программу (POSIX Threads).

// Должен быть как минимум:

//     Один поток, ожидающий pthread_join.

// Текст программы должен находиться в файле /home/box/main.cpp
// PID запущенного процесса должен быть сохранен в файле /home/box/main.pid

#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *pthread_func(void *unused)
{
    FILE *fd = fopen("/home/box/main.pid", "w");
    if (fd == NULL)
    {
        printf("Error opening a file: %d\n", errno);
        exit(1);
    }
    fprintf(fd, "%ld\n", (long)getpid());
    fflush(fd);
    fclose(fd);
    int count = 0;
    while (count < 10)
    {
        sleep(2);
        printf("%d ", count++);
    }
}

int main()
{
    pthread_t thread_id;
    printf("Start thread.\n");
    pthread_create(&thread_id, NULL, &pthread_func, NULL);

    pthread_join(thread_id, NULL);
    printf("Join thread. Exit.\n");
    return 0;
}