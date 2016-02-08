// Напишите многопоточную программу (POSIX Threads).

// Должны быть как минимум:

//     Один поток, ожидающий освобождения мьютекса.
//     Один поток, ожидающий освобождения спин-блокировки.
//     Два потока, ожидающих освобождения RW-блокировки (один должен ожидать чтения, другой - записи).

// Текст программы должен находиться в файле /home/box/main.cpp
// PID запущенного процесса должен быть сохранен в файле /home/box/main.pid

#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t func1_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_spinlock_t func2_mutex;
pthread_rwlock_t func34_mutex = PTHREAD_RWLOCK_INITIALIZER;

void *pthread_func1(void *unused)
{
    pthread_mutex_lock(&func1_mutex);
    printf("Func1 mutex lock.\n");
    pthread_mutex_unlock(&func1_mutex);
}

void *pthread_func2(void *unused)
{
    pthread_spin_lock(&func2_mutex);
    printf("Func2 mutex lock.\n");
    pthread_spin_unlock(&func2_mutex);
}

void *pthread_func3(void *unused)
{
    pthread_rwlock_wrlock(&func34_mutex);
    printf("Func3 mutex lock.\n");
    pthread_rwlock_unlock(&func34_mutex);
}

void *pthread_func4(void *unused)
{
    pthread_rwlock_rdlock(&func34_mutex);
    printf("Func3 mutex lock.\n");
    pthread_rwlock_unlock(&func34_mutex);
}

int main()
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
    // lock all mutex
    pthread_mutex_lock(&func1_mutex);
    pthread_spin_init(&func2_mutex, PTHREAD_PROCESS_PRIVATE);
    pthread_spin_lock(&func2_mutex);
    //pthread_rwspin_wrlock(&func34_mutex);
    //pthread_rwspin_rdlock(&func34_mutex);
    printf("All mutex locked.\n");

    pthread_t thread_id1, thread_id2, thread_id3, thread_id4;
    printf("Start thread1.\n");
    pthread_create(&thread_id1, NULL, &pthread_func1, NULL);
    printf("Start thread2.\n");
    pthread_create(&thread_id2, NULL, &pthread_func2, NULL);
    printf("Start thread3.\n");
    pthread_create(&thread_id3, NULL, &pthread_func3, NULL);
    printf("Start thread4.\n");
    pthread_create(&thread_id4, NULL, &pthread_func4, NULL);

    pthread_join(thread_id1, NULL);
    printf("Join thread1. Exit.\n");
    pthread_join(thread_id2, NULL);
    printf("Join thread2. Exit.\n");
    pthread_join(thread_id3, NULL);
    printf("Join thread3. Exit.\n");
    pthread_join(thread_id4, NULL);
    printf("Join thread4. Exit.\n");
    return 0;
}