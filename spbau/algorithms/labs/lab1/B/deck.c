#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct deck_t {
	int bottom;
	int size;
	int len;
	int *buffer;
};

inline void clear_deck(struct deck_t * deck);

inline void init_deck(struct deck_t * deck, int size)
{
	deck->buffer = NULL;
	deck->buffer = (int*) malloc(size*sizeof(int));

	assert(deck->buffer != NULL);

	deck->size = size;
	clear_deck(deck);
}

inline void delete_deck(struct deck_t * deck)
{
	free(deck->buffer);
	deck->buffer = NULL;
	deck->len = deck->size = deck->bottom = -1;
}

inline void clear_deck(struct deck_t * deck)
{
	deck->len = 0;
	deck->bottom = deck->size>>1;
}

inline int size(struct deck_t * deck)
{
	assert(deck->len != -1);

	return deck->len;
}

inline int isempty(struct deck_t * deck)
{
	return (size(deck) == 0);
}

int front(struct deck_t * deck)
{
	int pos = deck->bottom;

	assert(!isempty(deck));

	if (pos == deck->size-1)
		pos = 0;
	else
		pos++;

	return deck->buffer[pos];
}

inline int back(struct deck_t * deck)
{
	int pos = (deck->bottom + deck->len)%deck->size;

	assert(!isempty(deck));

	return deck->buffer[pos];
}

int pop_front(struct deck_t * deck)
{
	int value = front(deck);

	if (deck->bottom == deck->size-1)
		deck->bottom = 0;
	else
		deck->bottom++;
	deck->len--;

	return value;
}

int pop_back(struct deck_t * deck)
{
	int value = back(deck);

	deck->len--;

	return value;
}

void push_front(struct deck_t * deck, int value)
{
	assert((deck->len!=-1)&&(deck->len<deck->size));

	deck->buffer[deck->bottom] = value;

	if (deck->bottom == 0)
		deck->bottom = deck->size-1;
	else
		deck->bottom--;

	deck->len++;
}

void push_back(struct deck_t * deck, int value)
{
	int pos;

	assert((deck->len!=-1)&&(deck->len<deck->size));

	deck->len++;
	pos = (deck->bottom + deck->len)%deck->size;
	deck->buffer[pos] = value;
}

int main()
{
	char cmd[12];
	int value, finish = 0;
	struct deck_t deck;

	init_deck(&deck, 101);

	while ((!finish)&&(scanf("%s", cmd)!=EOF)) {
		if (!strcmp(cmd, "push_front")) {
			scanf("%d", &value);
			push_front(&deck, value);
			printf("ok\n");
		} else if (!strcmp(cmd, "push_back")) {
			scanf("%d", &value);
			push_back(&deck, value);
			printf("ok\n");
		} else if (!strcmp(cmd, "pop_front")) {
			if (!isempty(&deck))
				printf("%d\n", pop_front(&deck));
			else
				printf("error\n");
		} else if (!strcmp(cmd, "pop_back")) {
			if (!isempty(&deck))
				printf("%d\n", pop_back(&deck));
			else
				printf("error\n");
		} else if (!strcmp(cmd, "front")) {
			if (!isempty(&deck))
				printf("%d\n", front(&deck));
			else
				printf("error\n");
		} else if (!strcmp(cmd, "back")) {
			if (!isempty(&deck))
				printf("%d\n", back(&deck));
			else
				printf("error\n");
		} else if (!strcmp(cmd, "size")) {
			printf("%d\n", size(&deck));
		} else if (!strcmp(cmd, "clear")) {
			clear_deck(&deck);
			printf("ok\n");
		} else if (!strcmp(cmd, "exit")) {
			printf("bye\n");
			finish = 1;
		} else exit(1);
	}

	delete_deck(&deck);

	return 0;
}
