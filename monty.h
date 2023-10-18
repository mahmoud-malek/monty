#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

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

/**
 * struct all_s - A structure to hold global variables.
 * @arg: The argument for a Monty byte code operation.
 * @line: The line from the Monty byte code file.
 * @file: The Monty byte code file.
 * @stack: A flag to indicate if the stack should be treated as a queue.
 *
 * This structure is used to hold variables that need to be accessed
 * throughout the execution of the Monty byte code interpreter. This includes
 * the argument for an operation, the line being interpreted, the file being
 * read, and a flag to indicate if the stack should be treated as a queue.
 */

typedef struct all_s
{
	char *arg;
	char *line;
	FILE *file;
	int stack;
} all_t;

extern all_t ALL;

stack_t *add_node(stack_t **head, const int n);
stack_t *add_node_end(stack_t **head, const int n);
void free_list(stack_t *head);
int cmd_handler(char *line, stack_t **stack, unsigned int line_num,
				FILE *file);
void mypush(stack_t **stack, unsigned int line_number);
int _isdigit(char *str);
void mypall(stack_t **stack, unsigned int line_number);
void mypint(stack_t **stack, unsigned int line_number);
void mypop(stack_t **stack, unsigned int line_number);
void myswap(stack_t **stack, unsigned int line_number);
void myadd(stack_t **stack, unsigned int line_number);
void mynop(stack_t **stack, unsigned int line_number);
void mysub(stack_t **stack, unsigned int line_number);
void mymod(stack_t **stack, unsigned int line_number);
void mymul(stack_t **stack, unsigned int line_number);
void mydiv(stack_t **stack, unsigned int line_number);
void mypchar(stack_t **stack, unsigned int line_number);
void mypstr(stack_t **stack, unsigned int line_number);
void myrotl(stack_t **stack, unsigned int line_number);
void myrotr(stack_t **stack, unsigned int line_number);
void mystack(stack_t **stack, unsigned int line_number);
void myqueue(stack_t **stack, unsigned int line_number);

#endif /*MONTY HEADER  FILE*/
