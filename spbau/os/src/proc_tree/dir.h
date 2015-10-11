#ifndef _DIR_H_
#define _DIR_H_

#include <dirent.h>

typedef void (*dir_action)(struct dirent *ent);

void scan_dir(const char* name, dir_action do_this)
{
	DIR *dir = opendir(name);
	struct dirent *entry;

	while ((entry = readdir(dir)) != NULL)
		do_this(entry);

	closedir(dir);
}

#endif