#ifndef _PROCS_H_
#define _PROCS_H_

#include <stddef.h>

#define NAMELEN 256

struct process {
	pid_t pid;
	pid_t ppid;
	char name[NAMELEN];
	struct process *next;
	struct process *neib;
	struct process *child;
};

typedef void (*dofunc)(struct process *p, int depth);

void build_tree(struct process *list)
{
	struct process *temp = list, *child = NULL;

	while (temp) {
		child = list;
		while (child) {
			if ((child!=temp)&&(child->ppid==temp->pid)) {
				child->neib = temp->child;
				temp->child = child;
			}
			child=child->next;
		}
		temp = temp->next;
	}
}

void travel(struct process *tree, dofunc doit, int depth)
{
	struct process *child = NULL;

	if (tree) {
		child = tree->child;
		doit(tree, depth);
		depth++;
		while (child) {
			travel(child, doit, depth);
			child = child->neib;
		}
		depth--;
	}
}

void traversal(struct process *p, dofunc doit)
{
	int depth = 0;

	while (p) {
		if (p->ppid==0)
			travel(p, doit, depth);
		p=p->next;
	}
}

#endif
