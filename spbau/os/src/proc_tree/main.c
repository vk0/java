#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#include "procs.h"
#include "dir.h"

struct process *plist = NULL;

void read_process(struct dirent *ent)
{
	char *tail, buffer[NAMELEN];
	FILE *proc_stat;
	pid_t pid, ppid;
	struct process *proc = NULL;

	pid = strtol(ent->d_name, &tail, 10);
	sprintf(buffer, "/proc/%d/status", pid);

	if ((!errno)&&(*tail=='\0')&&(proc_stat=fopen(buffer,"r"))) {
		fscanf(proc_stat, "Name: %s\n", buffer);
		fscanf(proc_stat, "State: S (sleeping)\n");
		fscanf(proc_stat, "Tgid: %*d\n");
		fscanf(proc_stat, "Pid: %*d\n");
		fscanf(proc_stat, "PPid: %d\n", &ppid);
		fclose(proc_stat);
		proc = (struct process*)
				malloc(sizeof(struct process));
		if (proc) {
			proc->child = NULL;
			proc->neib = NULL;
			strncpy(proc->name, buffer, NAMELEN);
			proc->pid = pid;
			proc->ppid = ppid;
			proc->next = plist;
			plist = proc;
		}
	}
}

void print_proc(struct process *p, int depth)
{
	while (depth--) printf("   ");
	printf("(PID=%d) %s\n", p->pid, p->name);
}

void delete_proc(struct process *p, int depth)
{
	free(p);
}

int main()
{
	scan_dir("/proc", read_process);
	build_tree(plist);
	traversal(plist, print_proc);
	traversal(plist, delete_proc);
}
