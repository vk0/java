#include <sys/shm.h>
#include <stdio.h>
int main (int argc, char ** argv)
{
    int shm_id;
    char * shm_buf;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    shm_id = atoi (argv[1]);
    shm_buf = (char *) shmat (shm_id, 0, 0);
    if (shm_buf == (char *) - 1) {
        fprintf (stderr, "shmat() error\n");
        return 1;
    }
    printf ("Message: %s\n", shm_buf);
    shmdt (shm_buf);
    return 0;
}