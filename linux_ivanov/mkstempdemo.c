#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main (void)
{
int fd;
char tfile[] = "/tmp/mydemo-XXXXXX";
char tmsg[] = "Hello World\n";
char ch;
fd = mkstemp (tfile);
if (fd == -1) {
fprintf (stderr, "mkstemp() error\n");
return 1;
}
printf ("Filename: %s\n", tfile);
if (write (fd, tmsg, strlen (tmsg)) == -1) {
fprintf (stderr, "write() error\n");
return 1;
}
if (unlink (tfile) == -1) {
fprintf (stderr, "unlink() error\n");
return 1;
}
if (lseek (fd, 0, SEEK_SET) == -1) {
fprintf (stderr, "lseek() error\n");
return 1;
}
while (read (fd, &ch, 1) > 0) {
write (1, &ch, 1);
}
close (fd);
return 0;
}