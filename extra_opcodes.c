#include "monty.h"

/**
 * mod - finds the modulus of the last two elements
 *
 * @tail: the last element in the linked list
 * @line: the line number in the file
 * Return: void
 */
void mod(stack_t **tail, unsigned int line)
{
	int result;
	stack_t *hold;

	if (*tail != NULL && (**tail).prev != NULL)
	{
		if ((**tail).n == 0)
			fprintf(stderr, "L%u: division by zero\n", line);
		else
		{
			result = (((**tail).prev)->n) % (**tail).n;
			hold = (**tail).prev;
			free(*tail);
			*tail = hold;
			(**tail).next = NULL;
			(**tail).n = result;
		}
	}
	else
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
}
