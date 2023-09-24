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

/**
 * pchar - prints the element at the top of the stack
 *
 * @tail: the last node in the linked list
 * @line: the line number in the file being read
 * Return: void, does not return anything
 */
void pchar(stack_t **tail, unsigned int line)
{
	if (*tail != NULL)
	{
		if ((**tail).n < 0 || (**tail).n > 127)
			fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		else
			fprintf(stdout, "%c\n", (char)(**tail).n);
	}
	else
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
}

/**
 * pstr - prints a string from the top of the stack
 *
 * @tail: the end of the linked list
 * @line: the line number in the file being read
 * Return: void
 */
void pstr(stack_t **tail, unsigned int line)
{
	stack_t *hold = *tail;

	(void)line;
	while (hold != NULL)
	{
		if ((*hold).n == 0 || (*hold).n < 0 || (*hold).n > 127)
			break;
		fprintf(stdout, "%c", (char)(*hold).n);
		hold = (*hold).prev;
	}
	fprintf(stdout, "\n");
}

/**
 * rotl - makes the last element first and second last last
 *
 * @tail: pointer to the last node of the list
 * @line: the line number in the file being read
 * Return: void
 */
void rotl(stack_t **tail, unsigned int line)
{
	stack_t *hold = *tail, *hold1, *hold2;

	(void)line;
	if ((**tail).prev != NULL)
		hold1 = (**tail).prev;
	if (*tail != NULL && (*hold).prev != NULL)
	{
		while (*tail != NULL)
		{
			if ((**tail).prev == NULL)
			{
				(**tail).prev = hold;
				hold2 = *tail;
				*tail = (**tail).prev;
				(**tail).prev = NULL;
				(**tail).next = hold2;
				*tail = hold1;
				(**tail).next = NULL;
				break;
			}
			*tail = (**tail).prev;
		}
	}
}

/**
 * rotr - rotates the stack from the bottom up
 *
 * @tail: the last node of the stack
 * @line: the line number in the file being read
 * Return: void
 */
void rotr(stack_t **tail, unsigned int line)
{
	stack_t *hold = *tail, *hold2 = *tail;
	int i = 0, j, temp;

	(void)line;
	while (*tail != NULL)
	{
		i++;
		if ((**tail).prev == NULL)
			break;
		*tail = (**tail).prev;
	}
	if (i > 1)
	{
		for (j = 0; j < (i / 2); j++)
		{
			temp = (*hold2).n;
			(*hold2).n = (**tail).n;
			(**tail).n = temp;
			hold2 = (*hold2).prev;
			*tail = (**tail).next;
		}
	}
	*tail = hold;
}
