#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>

#define CUTOFF 20

typedef int key_t;
typedef int value_t;

typedef struct __ctnode
{
	key_t x;
	value_t num;
	int y;
	struct __ctnode *parent;
	struct __ctnode *left;
	struct __ctnode *right;
} ctnode_t;

typedef ctnode_t *pctnode_t;

void insertion_sort(pctnode_t *array, int left, int right)
{
	int i, j;
	pctnode_t temp;

	for (j = left + 1; j < right; j++) {
		i = j - 1;
		temp = array[j];
		while ((i >= left) && (array[i]->x > temp->x)) {
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = temp;
	}
}

void quick_sort(pctnode_t *array, int left, int right)
{
	int l = left, r = right - 1;
	pctnode_t temp, p;

	if (right - left <= 1) return;
	p = array[l + rand() % (right - left)];

	do {
		while (array[l]->x < p->x) l++;
		while (array[r]->x > p->x) r--;

		if (l <= r) {
			temp = array[l];
			array[l] = array[r];
			array[r] = temp;
			l++; r--;
		}		
	} while (l <= r);

	if (r - left > CUTOFF)
		quick_sort(array, left, r + 1);
	else if (r > left)
		insertion_sort(array, left, r + 1);

	if (right - l > CUTOFF)
		quick_sort(array, l, right);
	else if (l < right - 1)
		insertion_sort(array, l, right);
}

static ctnode_t *nodes = NULL;
static pctnode_t *sorted = NULL;
static int size = 0;
static pctnode_t root;

void init()
{
	int i, y, x;

	scanf("%d", &size);
	if (size > 0) {
		nodes = (ctnode_t *)malloc(size*sizeof(ctnode_t));
		sorted = (pctnode_t *)malloc(size*sizeof(pctnode_t));
	}
	for (i = 0; i < size; i++) {
		scanf("%d %d", &x, &y);		
		nodes[i].x = x;
		nodes[i].y = -y;
		nodes[i].num = i+1;
		nodes[i].parent = NULL;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
		sorted[i] = nodes+i;
	}
	quick_sort(sorted, 0, size);
}

void build_tree()
{
	pctnode_t last = NULL;
	int i;

	if (size > 0) {
		root = sorted[0];
		last = root;
		for (i = 1; i < size; i++) {
			while (last->parent != NULL &&
						sorted[i]->y > last->y)
				last = last->parent;
			if (sorted[i]->y <= last->y) {
				sorted[i]->left = last->right;
				sorted[i]->parent = last;
				if (last->right)
					last->right->parent = sorted[i];
				last->right = sorted[i];
			} else {
				sorted[i]->left = last;
				last->parent = sorted[i];
				root = sorted[i];
			}
			last = sorted[i];
		}
	}
}

void print_results()
{
	int p, l, r, i;
	printf("YES\n");
	for (i = 0; i < size; i++) {
		p = (nodes[i].parent) ? nodes[i].parent->num : 0;
		l = (nodes[i].left) ? nodes[i].left->num : 0;
		r = (nodes[i].right) ? nodes[i].right->num : 0;
		printf("%d %d %d\n", p, l, r);
	}
}

void finit()
{
	free(nodes);
	free(sorted);
}

int main()
{
	srand(time(NULL));
	init();
	build_tree();
	print_results();
	finit();

	return 0;
}
