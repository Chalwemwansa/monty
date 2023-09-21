#include "monty.h"
#include "extern.h"

/**
 * main - gets a file from the commandline
 *
 * @argv: the arguments vector passed to the terminal
 * @argc: the number of arguments passed to the terminal
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	handleFile(argv[1]);

	My_func(&stack);
	return (0);
}
