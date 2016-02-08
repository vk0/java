// Создайте набор из 16 семафоров SysV с ключем:

// key_t key = ftok("/tmp/sem.temp", 1);

// Проинициализируйте их порядковыми номерами [0..15].

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

static int SEM_SIZE = 16;

int main()
{
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short int *array;
        struct seminfo * __buf;
    } argument;

    unsigned short values[SEM_SIZE];
    unsigned short i = 0;
    for (i = 0; i < SEM_SIZE; i++) values[i] = i;
    argument.array = values;
    key_t key = ftok("/tmp/sem.temp", 1);
    int semid = semget(key, SEM_SIZE, IPC_CREAT | 0666);
    if (semid == -1) {
        printf("semget error %d\n", errno);
        exit(1);
    }
    int res_ctl = semctl(semid, 0, SETALL, argument);
    if (res_ctl == -1) {
        printf("semctl error %d\n", errno);
        exit(1);
    }
    printf("All is done!\n");
    return 0;
}