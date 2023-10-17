#include "monty.h"

/**
 * mymod - Computes the remainder of the division of
 * the second top element of the stack by the top element.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the stack contains less than two elements, or if the top element of
 * the stack is 0, the function will print an error message to stderr
 * and exit with a status of EXIT_FAILURE.
 */

void mymod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	tmp->next->n %= tmp->n;
	*stack = tmp->next;
	free(tmp);
}

/**
 * mymul - Multiplies the second top element of the stack with the top element.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the stack contains less than two elements, the function will print an
 * error message to stderr and exit with a status of EXIT_FAILURE.
 */
void mymul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	tmp->next->n *= tmp->n;
	*stack = tmp->next;
	free(tmp);
}

/**
 * mypchar - Prints the char at the top of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * The char to be printed is the ASCII equivalent of
 *  the integer at the top of the stack.
 * If the stack is empty, or if the integer at the top of the
 *  stack does not represent a valid ASCII value,
 * the function will print an error message to stderr and exit with
 * a status of EXIT_FAILURE.
 */

void mypchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * mypstr - Prints the string starting at the top of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * The function stops printing when either the stack is over,
 * the value of the element is 0,
 * or the value of the element does not represent a char.
 */
void mypstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp && tmp->n > 0 && tmp->n <= 127)
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}

/**
 * myrotl - Rotates the stack to the top.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * The top element of the stack becomes the last one,
 * and the second top element becomes the first one.
 */
void myrotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *last_node;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		last_node = tmp;

		last_node->next = *stack;
		(*stack)->prev = last_node;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last_node->next->next = NULL;
	}
}
