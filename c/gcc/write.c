/* rw.c */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>	/* read(), write(), close() */
#include <fcntl.h>	/* open(), O_RDONLY */
#include <sys/stat.h>	/* S_IRUSR */
#include <sys/types.h>	/* mode_t */

#define BUFFER_SIZE	64

int main (int argc, char ** argv)
{
	int fd;
	ssize_t read_bytes;
	ssize_t written_bytes;
	char buffer[BUFFER_SIZE];
	if (argc < 2)
	{
		fprintf (stderr, "Too few arguments\n");
		exit (1);
	}

	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf (stderr, "Cannot open file\n");
		exit (1);
	}	
	
	while ((read_bytes = read (fd, buffer, BUFFER_SIZE)) > 0)
	{		
		/* 1 == stdout */
		written_bytes = write (1, buffer, read_bytes);
		if (written_bytes != read_bytes)
		{
			fprintf (stderr, "Cannot write\n");
			exit (1);
		}
	}

	if (read_bytes < 0)
	{
		fprintf (stderr, "myread: Cannot read file\n");
		exit (1);
	}
	close (fd);
	exit (0);
}

