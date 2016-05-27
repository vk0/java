// Например, программа, которая отслеживает появление в каталоге нового файла и сразу же переносит этот файл в другой каталог.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
int main(int argc, char **argv)
{
    DIR *dd;
    struct dirent *de;
    struct timespec ts;
    char in_path[PATH_MAX + 1];
    char out_path[PATH_MAX + 1];
    if (argc != 3) {
        fprintf(stderr, "too few arguments\n");
        exit(1);
    }
    while (1) {
        if (!(dd = opendir(argv[1]))) {
            perror("opendir");
            exit(1);
        }
        while ((de = readdir(dd))) {
            if (strcmp(de->d_name, ".") && strcmp(de->d_name, ".."))
                break;
        }
        if (!de) {
            closedir(dd);
            ts.tv_sec = 0;
            ts.tv_nsec = 1;
            nanosleep(&ts, NULL);
        } else {
            strcpy(in_path, argv[1]);
            strcat(in_path, "/");
            strcat(in_path, de->d_name);
            strcpy(out_path, argv[2]);
            strcat(out_path, "/");
            strcat(out_path, de->d_name);
            if (rename(in_path, out_path) < 0) {
                perror("rename");
                exit(1);
            }
            closedir(dd);
        }
    }
    return 0;
}