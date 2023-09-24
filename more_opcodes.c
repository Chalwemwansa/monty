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
 * nop - function does not do anything
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
/**
 * sub - subtracts the last two elements in a linked list
 *
 * @tail: the end of the linked list
 * @line: the line number in the file being read
 * Return: void, does not return anything
 */

void sub(stack_t **tail, unsigned int line)
{
	int difference;
	stack_t *hold;

	if (*tail != NULL && (**tail).prev != NULL)
	{
		difference = (((**tail).prev)->n) - (**tail).n;
		hold = (**tail).prev;
		free(*tail);
		*tail = hold;
		(**tail).next = NULL;
		(**tail).n = difference;
	}
	else
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
}
/**
 * divide - divides the last tewo elements of the stack
 *
 * @tail: the tail of the linked list
 * @line: the line number in the file
 * Return: void
 */
void divide(stack_t **tail, unsigned int line)
{
	int result;
	stack_t *hold;

	if (*tail != NULL && (**tail).prev != NULL)
	{
		if ((**tail).n == 0)
			fprintf(stderr, "L%u: division by zero\n", line);
		else
		{
			result = (((**tail).prev)->n) / (**tail).n;
			hold = (**tail).prev;
			free(*tail);
			*tail = hold;
			(**tail).next = NULL;
			(**tail).n = result;
		}
	}
	else
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
}

/**
 * mul - multiplies the last two elements of the linked list
 *
 * @tail: the last element of the linked list
 * @line: the line number in the linked list
 * Return: void
 */
void mul(stack_t **tail, unsigned int line)
{
	int result;
	stack_t *hold;

	if (*tail != NULL && (**tail).prev != NULL)
	{
		result = (((**tail).prev)->n) * (**tail).n;
		hold = (**tail).prev;
		free(*tail);
		*tail = hold;
		(**tail).next = NULL;
		(**tail).n = result;
	}
	else
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
}
