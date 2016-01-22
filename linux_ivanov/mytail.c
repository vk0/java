#include <stdlib.h>
#include <stdio.h>

int main (int argc, char ** argv)
{
FILE * infile;
int ch;
long int nback;

if (argc < 3) {
    fprintf (stderr, "Too few arguments\n");
    return 1;
}

infile = fopen (argv[1], "r");

if (infile == NULL) {
    fprintf (stderr, "Cannot open "
        "input file (%s)\n", argv[1]);
        return 1;
}

nback = abs (atoi (argv[2]));
fseek (infile, 0, SEEK_END);
if (nback > ftell (infile))
    fseek (infile, 0, SEEK_SET);
else
    fseek (infile, -nback, SEEK_END);
while ((ch = fgetc (infile)) != EOF)
    fputc (ch, stdout);
    fclose (infile);
    return 0;
}