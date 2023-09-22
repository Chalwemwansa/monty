#include "monty.h"
#include "extern.h"

/**
 * push - places an element on to the stack
 *
 * @head: point to add element
 * @line: the line number in the file
 * Return: void
 */
void push(stack_t **head, unsigned int line)
{
	stack_t *node = malloc(sizeof(stack_t));
	(void)line;

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	(*node).n = digit;
	if (*head == NULL)
	{
		(*node).prev = NULL;
		(*node).next = NULL;
	}
	else
	{
		(*node).prev = *head;
		(*node).next = NULL;
	}
	*head = node;
}

/**
 * pall - displays all the contents of the linked list
 *
 * @tail: the end of the list
 * @line: the line number
 * Return: void
 */
void pall(stack_t **tail, unsigned int line)
{
	stack_t *hold = *tail;
	(void)line;

	while (*tail != NULL)
	{
		fprintf(stdout, "%d\n", (**tail).n);
		*tail = (**tail).prev;
	}
	*tail = hold;
}

/**
 * pint - prints the topmost member of the linked list
 *
 * @tail: the last element of the linked list
 * @line: the line number
 * Return: void
 */
void pint(stack_t **tail, unsigned int line)
{
	if (*tail == NULL)
	fprintf(stderr, "L%u: can't pint, stack empty\n", line);

	if (*tail != NULL)
	fprintf(stdout, "%d\n", (**tail).n);
}

/**
 * pop - removes the element at the tail
 *
 * @tail: the last element of the linked list
 * @line: the line number
 * Return: void
 */
void pop(stack_t **tail, unsigned int line)
{
	stack_t *hold = *tail;

	if (*tail == NULL)
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);

	if (*tail != NULL)
	{
		hold = (**tail).prev;
		free(*tail);
		*tail = hold;
		if (*tail != NULL)
			(**tail).next = NULL;
	}
}

/**
 * swap - swaps the last two elements
 *
 * @tail: the last element of the linked list
 * @line: the line number
 * Return: void
 */
void swap(stack_t **tail, unsigned int line)
{
	if (*tail != NULL && (**tail).prev != NULL)
	{
		int n = (**tail).n;
		(**tail).n = ((**tail).prev)->n;
		((**tail).prev)->n = n;
	}
	else
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
}
