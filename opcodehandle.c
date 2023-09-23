#include "monty.h"
#include "extern.h"

/**
 * handleOpcode - handles the opcodes passed
 *
 * @str: the opcode
 * @value: the argument passed
 * @lineNum: the line in the file
 * Return: void
 */
int handleOpcode(char *str, char *value, unsigned int lineNum)
{
	int i, flag = 0;
	instruction_t opcodes[12] = {{"push", push},
					{"pall", pall},
					{"pint", pint},
					{"pop", pop},
					{"swap", swap},
					{"add", add},
					{"nop", nop},
					{"sub", sub},
					{"div", divide},
					{"mul", mul},
					{"mod", mod},
					{NULL, NULL}
	};
	if (str == NULL)
		return (0);
	flag = getflag(str, value);
	if (flag == 0)
		digit = _atoi(value);
	if (flag == 2)
	{
		fprintf(stderr, "L%u: usage: push integer\n", lineNum);
		return (2);
	}
	for (i = 0; i < 12; i++)
	{
		if (_strcmp(opcodes[i].opcode, str) == 0)
		{
			(opcodes[i]).f(&stack, lineNum);
			break;
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", lineNum, str);
			return (2);
		}
	}
	if (flag == 3)
		return (2);
	return (0);
}
