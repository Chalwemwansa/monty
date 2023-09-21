#include "monty.h"

/**
 * add - adds the last two numbers in a linked list
 *
 * @tail: the tail of the linked list
 * @line: the line number in the file being read
 * Return: void
 */
void add(stack_t **tail, unsigned int line)
{
	int sum;
	stack_t *hold;

	if (*tail != NULL && (**tail).prev != NULL)
	{
		sum = ((**tail).n + ((**tail).prev)->n);
		hold = (**tail).prev;
		free(*tail);
		*tail = hold;
		(**tail).next = NULL;
		(**tail).n = sum;
	}
	else
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
}

/**
 * nop - does not do anything
 *
 * @tail: the tail of the linked list
 * @line: the line number in the file being read
 * Return: void
 */
void nop(stack_t **tail, unsigned int line)
{
	(void)tail;
	(void)line;
}
