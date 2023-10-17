#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the argument given is not a digit, or if add_node fails, the
 * function will print an error message to stderr and exit with a status
 * of EXIT_FAILURE.
 */

void push(stack_t **stack, unsigned int line_number)
{
	int num;

	if (_isdigit(ALL.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	num = atoi(ALL.arg);
	if (add_node(stack, num) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * All values are printed as integers followed by a new line character.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the stack is empty, the function will print an error message to stderr
 * and exit with a status of EXIT_FAILURE.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
