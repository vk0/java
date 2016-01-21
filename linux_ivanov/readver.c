#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STR_SIZE 1024

int readver(char * str)
{
    int i;
    FILE * fp = fopen("/proc/version", "r");
    if (!fp) {
       fprintf(stderr, "Cannot open /proc/version\n");
       return 1;
    }
    for (i = 0; (i < STR_SIZE) &&
        ((str[i] = fgetc(fp)) != EOF); i++);
    str[i] = '\0';
    fclose (fp);
    return 0;
}

void toup(char * str)
{
    int i;
    for (i = 0; i < strlen (str); i++)
    str[i] = toupper (str[i]);
}

int main (void)
{
    char * str = (char*) malloc(STR_SIZE * sizeof(char));
    if (str == NULL) {
        fprintf (stderr, "Cannot allocate memory\n");
        return 1;
    }
    if (readver(str) != 0) {
        fprintf (stderr, "Failed\n");
        return 1;
    }
    printf ("%s\n", str);
    toup(str);
    printf ("%s\n", str);
    free(str);
    return 0;
}