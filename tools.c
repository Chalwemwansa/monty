#include "monty.h"

/**
 * _atoi - function converts a string to an integer
 * Return: an integer
 * @s: the string
 */

int _atoi(char *s)
{
int i = 0, d = 0, n = 0, len = 0, digit = 0;

if (s == NULL)
	return (0);
while (s[len] != '\0')
	len++;
while (i < len)
{
d = 0;
if (s[0] == '-')
	++d;
if ((s[i] >= '0' && s[i] <= '9'))
{
	digit = s[i] - '0';
	if (d == 1)
	digit = -digit;
	n = n * 10 + digit;
}
i++;
}
return (n);
}
/**
 * My_func - frees a linked list
 *
 * @tail: pointer to the tail of the function
 * Return: void
 */
void My_func(stack_t **tail)
{
	stack_t *hold;

	while (*tail != NULL)
	{
		hold = (**tail).prev;
		free(*tail);
		*tail = hold;
	}
}

/**
 * intcheck - checks if value is an integer
 * @str: string passed as parameter
 * @value: the value added
 * Return: an int
 */
int intcheck(char *str, char *value)
{
	int ch = 0;

	if (value == NULL && _strcmp(str, "push") == 0)
		return (2);
	if (value[0] == '-' || value[0] == '+')
		ch = 1;
	if (ch != 1 && (value[0] < '0' || value[0] > '9'))
		return (2);
	ch = 1;
	while (value[ch] != '\0')
	{
		if (value[ch] < '0' || value[ch] > '9')
			return (2);
		ch++;
	}
	return (0);
}

/**
 * getflag - checks if _atoi should take place
 *
 * @str: parameter used
 * @value: the digit after the opcode
 * Return: an int
 */
int getflag(char *str, char *value)
{
	int ch = 0;
	char *check[14] = {"pint", "pchar",  "pop", "add", "sub", "mul",
		"div", "mod", "swap", "nop", "pall", "pstr", "rotl", "rotr"};

	if (stack != NULL)
	{
	if ((_strcmp(str, "div") == 0 || _strcmp(str, "mod") == 0) && (*stack).n == 0)
		return (3);
	if (_strcmp(str, "pchar") == 0 && ((*stack).n < 0 || (*stack).n > 127))
		return (3);
	}
	while (ch < 14)
	{
		if (_strcmp(str, check[ch]) == 0)
		{
			if (ch > 8)
				return (1);
			if (stack == NULL && ch <= 8)
				return (3);
			if ((*stack).prev == NULL && ch > 2)
				return (3);
			if (ch > 2 && ch <= 8)
				return (1);
		}
		ch++;
	}
	if (_strcmp(str, "push") != 0)
		return (1);
	return (intcheck(str, value));
}
