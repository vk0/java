/* openclose.c */
#include <fcntl.h>	/* open() and O_XXX flags */
#include <sys/stat.h>	/* S_IXXX flags */
#include <sys/types.h>	/* mode_t */
#include <unistd.h>	/* close() */
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char ** argv)
{
	int fd;
	mode_t mode = S_IRUSR | S_IWUSR; 
	int flags = O_WRONLY | O_CREAT | O_EXCL;
	if (argc < 2)
	{
		fprintf (stderr, "openclose: Too few arguments\n");
		fprintf (stderr, "Usage: openclose <filename>\n");
		exit (1);
	}

	fd = open (argv[1], flags, mode);
	if (fd < 0)
	{
		fprintf (stderr, "openclose: Cannot open file '%s'\n",
				argv[1]);
		exit (1);
	}
	
	if (close (fd) != 0)
	{
		fprintf (stderr, "Cannot close file (descriptor=%d)\n", fd);
		exit (1);
	}	
	exit (0);
}
