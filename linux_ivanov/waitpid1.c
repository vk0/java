#include <wait.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main (int argc, char ** argv)
{
pid_t child;
int status;
if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}
/* Child */
if (!(child = fork ())) {
    execlp ("ls", "ls", argv[1], NULL);
    fprintf (stderr, "Exec error\n");
}
/* Parent */
waitpid (child, &status, 0);
if (WIFEXITED (status)) {
    printf ("Exitcode=%d\n",WEXITSTATUS (status));
}
return 0;
}