// Создайте семафор POSIX с именем:

// /test.sem


// Проинициализируйте его числом 66.

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

static unsigned SEM_VAL = 66;

int main()
{

    sem_t *semid = sem_open("/test.sem", O_CREAT, 0666, SEM_VAL);
    if (semid == SEM_FAILED) {
        printf("sem_open error %d\n", errno);
        exit(1);
    }
    //sem_close(semid);
    printf("All is done!\n");
    return 0;
}