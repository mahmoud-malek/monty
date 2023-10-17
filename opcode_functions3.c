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
