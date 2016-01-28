#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
extern char ** environ;
int main (void)
{
pid_t result;
result = fork ();

if (result == -1) {
    fprintf (stderr, "Fork error\n");
    return 1;
}
/* Child */
if (result == 0) {
    execle ("/bin/ls", "ls", "-l", "/", NULL, environ);
    fprintf (stderr, "Exec error\n");
    return 1;
}
/* Parent */
return 0;
}