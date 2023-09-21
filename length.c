#include "monty.h"

/**
 * _len - finds the length of a string
 *
 * @str: the parameter used
 * Return: length of a string
 */
int _len(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}
