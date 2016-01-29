#include <sys/statvfs.h>
#include <mntent.h>
#include <stdio.h>
int main (void)
{
struct mntent * entry;
struct statvfs fs;

FILE * file;
file = setmntent ("/etc/mtab", "r");

if (file == NULL) {
    fprintf (stderr, "Cannot open /etc/mtab\n");
    return 1;
}
while ((entry = getmntent (file)) != NULL) {
    if (statvfs (entry->mnt_dir, &fs) == -1) {
        fprintf (stderr, "statvfs() error\n");
        return 1;
}

printf ("Filesystem: %s\n", entry->mnt_fsname);
printf ("Mountpoint: %s\n", entry->mnt_dir);
printf ("Block size: %ld\n", (unsigned long int) fs.f_bsize);
printf ("Blocks: %ld\n", (unsigned long int) fs.f_blocks);
printf ("Blocks free: %ld\n", (unsigned long int) fs.f_bfree);

printf ("Blocks available: %ld\n", (unsigned long int) fs.f_bavail);
printf ("Max. filename length: %ld\n", (unsigned long int) fs.f_namemax);

printf ("---\n");
}
endmntent (file);
return 0;
}