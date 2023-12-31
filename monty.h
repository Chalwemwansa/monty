#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int digit;
extern stack_t *stack;
extern int mode;

	/* opcodes */
void push(stack_t **head, unsigned int line);
void pall(stack_t **tail, unsigned int line);
void pint(stack_t **tail, unsigned int line);
void pop(stack_t **tail, unsigned int line);
void swap(stack_t **tail, unsigned int line);
void add(stack_t **tail, unsigned int line);
void nop(stack_t **tail, unsigned int line);
void sub(stack_t **tail, unsigned int line);
void divide(stack_t **tail, unsigned int linen);
void mul(stack_t **tail, unsigned int line);
void mod(stack_t **tail, unsigned int line);
void pchar(stack_t **tail, unsigned int line);
void pstr(stack_t **tail, unsigned int line);
void rotl(stack_t **tail, unsigned int line);
void rotr(stack_t **tail, unsigned int line);

	/* tools */
int _len(char *str);
void handleFile(char *str);
int _atoi(char *sr);
int handleOpcode(char *str, char *value, unsigned int lineNum);
int _strcmp(char *s1, char *s2);
void My_func(stack_t **tail);
int getflag(char *str, char *value);

#endif
