#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define CUTOFF 40

struct shelter_t {
	int num;
	unsigned int pos;
};

int bin_search(struct shelter_t *array, int size, unsigned int pos)
{
	int left = 0;
	int right = size - 1;
	int middle;

	assert(size != 0);

	if (array[0].pos > pos) return 0;
	else if (array[right].pos < pos) return right;

	while (right - left > 0) {
		middle = left + ((right - left) >> 1);

		if (pos > array[middle].pos)
			left = middle + 1;
		else if (pos < array[middle].pos)
			right = middle;
		else
			return middle;
	}

	if (array[right].pos - pos > pos - array[right - 1].pos)
		return right - 1;
	else
		return right;
}

void insertion_sort(struct shelter_t *array,
			int left, int right)
{
	int i, j;
	struct shelter_t temp;

	for (j = left + 1; j < right; j++) {
		i = j - 1;
		temp = array[j];
		while ((i >= left) && (array[i].pos > temp.pos)) {
			array[i + 1] = array[i];
			i--;
		}
		array[i + 1] = temp;
	}
}

void quick_sort(struct shelter_t *array,
			int left, int right)
{
	int l = left, r = right - 1;
	struct shelter_t temp;
	unsigned int p;

	p = array[l + rand() % (right - left)].pos;

	do {
		while (array[l].pos < p) l++;
		while (array[r].pos > p) r--;

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

inline int init_cities(unsigned int **cities)
{
	int count, i;

	scanf("%d\n", &count);
	*cities = (unsigned int *)
		malloc(count * sizeof(unsigned int));

	for (i = 0; i < count; i++)
		scanf("%d", (*cities + i));

	return count;
}

inline int init_shelters(struct shelter_t **shelters)
{
	int count, i;

	scanf("%d\n", &count);
	*shelters = (struct shelter_t *)
		malloc(count * sizeof(struct shelter_t));

	for (i = 0; i < count; i++) {
		scanf("%d", &((*shelters + i)->pos));
		(*shelters + i)->num = i + 1;
	}

	return count;
}

int main()
{
	int count_of_cities, count_of_shelters, city, shelter;
	struct shelter_t *shelters;
	unsigned int *cities;

	srand(time(NULL));

	count_of_cities = init_cities(&cities);
	count_of_shelters = init_shelters(&shelters);

	quick_sort(shelters, 0, count_of_shelters);

	for (city = 0; city < count_of_cities; city++) {
		shelter = bin_search(shelters, count_of_shelters,
						cities[city]);
		printf("%d ", shelters[shelter].num);
	}

	free(cities);
	free(shelters);

	return 0;
}
