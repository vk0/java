#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#define SHMEM_SIZE 4096
#define SH_MESSAGE "Hello World!\n"
int main (void)
{
    int shm_id;
    char * shm_buf;
    int shm_size;
    struct shmid_ds ds;
    shm_id = shmget (IPC_PRIVATE, SHMEM_SIZE,
                     IPC_CREAT | IPC_EXCL | 0600);
    if (shm_id == -1) {
        fprintf (stderr, "shmget() error\n");
        return 1;
    }
    shm_buf = (char *) shmat (shm_id, NULL, 0);
    if (shm_buf == (char *) - 1) {
        fprintf (stderr, "shmat() error\n");
        return 1;
    }
    shmctl (shm_id, IPC_STAT, &ds);
    shm_size = ds.shm_segsz;
    if (shm_size < strlen (SH_MESSAGE)) {
        fprintf (stderr, "error: segsize=%d\n", shm_size);
        return 1;
    }
    strcpy (shm_buf, SH_MESSAGE);
    printf ("ID: %d\n", shm_id);
    printf ("Press <Enter> to exit...");
    fgetc (stdin);
    shmdt (shm_buf);
    shmctl (shm_id, IPC_RMID, NULL);
    return 0;
}