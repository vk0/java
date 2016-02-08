// Создайте общую память POSIX с именем:

// /test.shm

// Размер сегмента должен быть 1 мегабайт. Заполните каждый байт числом 13.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <semaphore.h>

static off_t SHM_SIZE = 0x400 * 0x400; // 1 Mbyte

int main()
{
    int fd = shm_open("/test.shm", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        printf("shm_open error %d\n", errno);
        exit(1);
    }
    int res_tr = ftruncate(fd, SHM_SIZE);
    if (res_tr == -1) {
        printf("ftruncate error %d\n", errno);
        exit(1);
    }
    char *shared_memory = (char *)mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (shared_memory == MAP_FAILED) {
        printf("mmap error %d\n", errno);
        exit(1);
    }
    printf("Init shared mem at %p\n", shared_memory);
    const char val = 13;
    void *p = memset(shared_memory, val, SHM_SIZE);
    printf("All is done! %zd bytes writes at %p\n", SHM_SIZE, p);
    return 0;
}