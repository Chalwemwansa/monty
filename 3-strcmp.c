#include "monty.h"
/**
 * _strcmp - function compares two strings if they are the same
 * Return: the difference between the two after comparing
 * @s1: variable to be used in the code
 * @s2: variable to be used in the program
 */

int _strcmp(char *s1, char *s2)
{
int i = 0, j = 0;

if (s1 == NULL || s2 == NULL)
	return (-1);
while (s1[i] != '\0' && (s2[j] != '\0'))
{
	if (s2[j] == ' ')
	{
		j++;
		continue;
	}
	if (s1[i] != s2[j])
		return (2);
	i++;
	j++;
}
if (s1[i] == '\0' && s2[j] != '\0')
	return (2);

return (0);
}
