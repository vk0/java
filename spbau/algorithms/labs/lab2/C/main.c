#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef struct __node {
	int num;
	struct __node *next;
} node_t;
typedef node_t *list_t;

typedef struct __point {
	int color;
	list_t edges;
} point_t;

typedef struct __graph {
	int size;
	point_t *points;
} graph_t;

list_t pop(list_t *list)
{
	list_t node = *list;

	if (*list != NULL)
		*list = node->next;
	else
		*list = NULL;

	return node;
}

list_t push(list_t list, list_t node)
{
	if (node != NULL) {
		node->next = list;
		return node;
	}

	return list;
}

inline list_t create_node(int num)
{
	list_t p = (list_t) malloc(sizeof(node_t));

	assert(p != NULL);
	p->num = num;
	p->next = NULL;

	return p;
}

void destroy_list(list_t lst)
{
	list_t node = NULL;

	while (lst != NULL) {
		node = lst;
		lst = lst->next;
		free(node);
	}
}

void create_graph(graph_t *gr, int size)
{
	int i;

	gr->size = size;
	gr->points = (point_t *) malloc((size+1)*sizeof(point_t));
	assert(gr->points != NULL);
	for (i = 0; i <= size; i++) {
		gr->points[i].edges = NULL;
		gr->points[i].color = -1;
	}
}

void destroy_graph(graph_t *gr)
{
	int i;

	for (i = 0; i <= gr->size; i++)
		destroy_list(gr->points[i].edges);
	free(gr->points);
}

void addedge(graph_t *gr, int point1, int point2)
{
	list_t node1 = NULL, node2 = NULL;

	assert(gr->size >= point1 && gr->size >= point2);
	node1 = create_node(point1);
	node2 = create_node(point2);
	assert(node1 != NULL && node2 != NULL);

	gr->points[point1].edges = push(gr->points[point1].edges, node2);
	gr->points[point2].edges = push(gr->points[point2].edges, node1);
}

int coloring(point_t *point, int color)
{
	if (point->color == -1) {
		point->color = color;
		return 0;
	} else if (point->color == color)
		return 1;
	else
		return -1;
}

int dfs_from_point_coloring(graph_t *gr, int num, int color)
{
	list_t curr = NULL;
	int rc = coloring(gr->points+num, color);

	if (rc == 0) {
		curr = gr->points[num].edges;
		while (curr != NULL && rc >= 0) {
			rc = dfs_from_point_coloring(gr, curr->num,
						(color+1)%2);
			curr = curr->next;
		}
	}

	return rc;
}

int dfs_coloring(graph_t *gr)
{
	int i, rc = 1;

	if (gr != NULL || gr->size != 0) {
		for (i = 1; i <= gr->size && rc >= 0; i++)
			if (gr->points[i].color == -1)
				rc = dfs_from_point_coloring(gr, i, 1);
	}

	return rc;
}

void printpoints(graph_t *gr)
{
	int i;

	if (gr != NULL && gr->size > 0) {
		for (i = 1; i <= gr->size; i++)
			if (gr->points[i].color == 1)
				printf("%d ", i);
	} 
}

static graph_t graph;

void init()
{
	int pairs, points, i;
	int point1, point2;

	scanf("%d %d", &points, &pairs);
	create_graph(&graph, points);
	for (i = 1; i <= pairs; i++) {
		scanf("%d %d", &point1, &point2);
		addedge(&graph, point1, point2);
	}
}

void finit()
{
	destroy_graph(&graph);
}

int main()
{
	init();
	if (dfs_coloring(&graph) != -1) {
		printf("YES\n");
		printpoints(&graph);
	} else
		printf("NO\n");
	finit();

	return 0;
}
