#include "monty.h"

/**
 * mypop - Removes the top element of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the stack is empty, the function will print an error message to stderr
 * and exit with a status of EXIT_FAILURE.
 */

void mypop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
}

/**
 * myswap - Swaps the top two elements of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the stack contains less than two elements, the function will print an
 * error message to stderr and exit with a status of EXIT_FAILURE.
 */

void myswap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * myadd - Adds the top two elements of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * The result is stored in the second top element of the stack, and the top
 * element is removed. If the stack contains less than two elements, the
 * function will print an error message to stderr and exit with a status of
 * EXIT_FAILURE.
 */

void myadd(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	mypop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * mynop - Does nothing.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * This function literally does nothing, regardless of the stack or the
 * line_number.
 */

void mynop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
