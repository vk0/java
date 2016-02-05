#include <stdio.h>
#include <getopt.h>

int main (int argc, char ** argv)
{
    FILE * outfile = stdout;
    int i, opt;
    char * filename = NULL;
    char help_str[] =
        "Usage: longoptdemo [OPTIONS] ARGUMENTS ...\n"
        "-h, --help — Print help and exit\n"
        "-o, --output <outfile> — Write output to file\n";

    const struct option long_opts[] = {
        { "help", no_argument, NULL, 'h' },
        { "output", required_argument, NULL, 'o' },
        { NULL, 0, NULL, 0 }
    };

    while ((opt = getopt_long (argc, argv, "ho:",
                               long_opts, NULL)) != -1) {
        switch (opt) {
        case 'h':
            printf ("%s", help_str);
            return 0;
        case 'o':
            filename = optarg;
            break;
        case '?':
            fprintf (stderr, "%s", help_str);
            return 1;
        default:
            fprintf (stderr, "Unknown error\n");
            return 1;
        }
    }
    if (optind >= argc) {
        fprintf (stderr,
                 "No argument(s) found\n%s", help_str);
        return 1;
    }
    if (filename != NULL) {
        outfile = fopen (filename, "w");
        if (outfile == NULL) {
            fprintf (stderr, "Cannot open "
                     "output file (%s)\n", filename);
            return 1;
        }
    }
    for (i = optind; i < argc; i++)
        fprintf (outfile, "%s\n", argv[i]);
    if (outfile != stdout) fclose (outfile);
    return 0;
}