#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <sys/types.h>
int main (int argc, char ** argv)
{
pid_t status, childpid;
int exit_status;

if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}
status = fork();
if (status == -1) {
    fprintf (stderr, "Fork error\n");
    return 1;
}
/* Child */
if (status == 0) {
    execlp ("ls", "ls", argv[1], NULL);
    fprintf (stderr, "Exec error\n");
    return 1;
}
/* Parent */
childpid = wait(&exit_status);
if (WIFEXITED (exit_status)) {
    printf ("Process with PID=%d "
        "has exited with code=%d\n", childpid,
    WEXITSTATUS (exit_status));
}
return 0;
}