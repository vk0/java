#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
int main (int argc, char ** argv)
{
struct stat st;

if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}
if (stat (argv[1], &st) == -1) {
    fprintf (stderr, "stat() error\n");
    return 1;
}
printf ("FILE:\t\t%s\n", argv[1]);
printf ("UID:\t\t%d\n", (int) st.st_uid);
printf ("GID:\t\t%d\n", (int) st.st_gid);
printf ("SIZE:\t\t%ld\n", (long int) st.st_size);
printf ("AT:\t\t%s", ctime (&st.st_atime));
printf ("MT:\t\t%s", ctime (&st.st_mtime));
return 0;
}