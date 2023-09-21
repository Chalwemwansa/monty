#define _GNU_SOURCE
#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "extern.h"

stack_t *stack;

/**
 * handleFile - handles the opening of a file
 *
 * @str: the parameter being used
 * Return: void
 */
void handleFile(char *str)
{
	char *buffer = NULL, *tocken;
	size_t n = 0, i, check;
	FILE *fd;
	unsigned int lineNum = 1;
	stack = NULL;

	fd = fopen(str, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &n, fd) != -1)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				buffer[i] = '\0';
			if (buffer[i] == '\t')
				buffer[i] = ' ';
			i++;
		}
		tocken = strtok(buffer, " ");
		check = handleOpcode(tocken, strtok(NULL, " "), lineNum);
		if (check == 2)
		{
			fclose(fd);
			free(buffer);
			My_func(&stack);
			exit(EXIT_FAILURE);
		}

		lineNum++;
		free(buffer);
		buffer = NULL;
	}
	free(buffer);
	fclose(fd);
}
