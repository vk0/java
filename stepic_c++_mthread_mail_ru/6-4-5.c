// Общая память SysV.

// Создайте общую память SysV (не менее 1 мегабайта) с ключем:

// key_t key = ftok("/tmp/mem.temp", 1);

// Каждый байт первого мегабайта общей памяти заполните числом 42.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>

static size_t SHM_SIZE = 0x400 * 0x400; // 1 Mbyte

int main()
{
    key_t key = ftok("/tmp/mem.temp", 1);
    int segid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (segid == -1) {
        printf("shmget error %d\n", errno);
        exit(1);
    }
    char *shared_memory;
    shared_memory = (char *)shmat(segid, 0, 0);
    if ((long)shared_memory == -1) {
        printf("shmat error %d\n", errno);
        exit(1);
    }
    const char val = 42;
    void *p = memset(shared_memory, val, SHM_SIZE);
    printf("All is done! %zu bytes writes at %p\n", SHM_SIZE, p);
    return 0;
}