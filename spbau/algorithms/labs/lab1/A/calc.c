#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

struct stack_t {
	int num;
	struct stack_t * next;
};

inline struct stack_t * create_node(int num)
{
	struct stack_t * node =
		(struct stack_t *) malloc(sizeof(struct stack_t));

	node->num = num;
	node->next = NULL;

	return node;
}

inline int isempty(struct stack_t * stack)
{
	return (stack == NULL);
}

inline int pop(struct stack_t ** stack)
{
	assert(*stack != NULL);

	struct stack_t * node = *stack;
	int num = node->num;
	*stack = node->next;
	free(node);

	return num;
}

inline void push(struct stack_t **stack, int num)
{
	struct stack_t * node = create_node(num);
	node->next = *stack;
	*stack = node;
}

int main()
{
	struct stack_t * stack = NULL;
	int input_char;
	int left_operand, right_operand;

	while ((input_char = getchar()) != EOF) {
		switch (input_char) {
			case '+':
				right_operand = pop(&stack);
				left_operand = pop(&stack);
				push(&stack, left_operand+right_operand);
				break;
			case '-':
				right_operand = pop(&stack);
				left_operand = pop(&stack);
				push(&stack, left_operand-right_operand);
				break;
			case '*':
				right_operand = pop(&stack);
				left_operand = pop(&stack);
				push(&stack, left_operand*right_operand);
				break;
			default:
				if (isdigit(input_char))
					push(&stack, input_char-'0');
				break;
		}
	}

	printf("%d", pop(&stack));

	assert(isempty(stack));

	return 0;
}
