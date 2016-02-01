#include <stdio.h>
#include <dirent.h>
int main (int argc, char ** argv)
{
DIR * dir;
struct dirent * entry;

if (argc < 2) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}
dir = opendir (argv[1]);
if (dir == NULL) {
    fprintf (stderr, "opendir() error\n");
    return 1;
}
while ((entry = readdir (dir)) != NULL)
    printf ("%s\n", entry->d_name);
closedir (dir);
return 0;
}