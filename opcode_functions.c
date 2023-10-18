#include "monty.h"

/**
 * mypush - Pushes an element to the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the argument given is not a digit, or if add_node fails, the
 * function will print an error message to stderr and exit with a status
 * of EXIT_FAILURE.
 */

void mypush(stack_t **stack, unsigned int line_number)
{
	int num;
	stack_t *tmp;

	if (_isdigit(ALL.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	num = atoi(ALL.arg);
	if (ALL.stack)
		tmp = add_node(stack, num);
	else
		tmp = add_node_end(stack, num);

	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * mypall - Prints all the values on the stack, starting from the top.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * All values are printed as integers followed by a new line character.
 */

void mypall(stack_t **stack, unsigned int line_number)
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
 * mypint - Prints the value at the top of the stack.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the stack is empty, the function will print an error message to stderr
 * and exit with a status of EXIT_FAILURE.
 */

void mypint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	if (!ALL.stack)
	{
		while (tmp->next)
			tmp = tmp->next;
	}

	printf("%d\n", tmp->n);
}

/**
 * mysub - Subtracts the top element of the stack from the second top element.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the stack contains less than two elements, the function will print an
 * error message to stderr and exit with a status of EXIT_FAILURE.
 */

void mysub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	if (!ALL.stack)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->n -= tmp->n;
		tmp->prev->next = NULL;
	}
	else
	{
		tmp->next->n -= tmp->n;
		*stack = tmp->next;
	}

	free(tmp);
}

/**
 * mydiv - Divides the second top element of the stack by the top element.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * If the stack contains less than two elements, or if the top element of
 * the stack is 0, the function will print an error message to stderr
 * and exit with a status of EXIT_FAILURE.
 */
void mydiv(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free(ALL.line);
		fclose(ALL.file);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	if (!ALL.stack)
	{
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free(ALL.line);
			fclose(ALL.file);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		tmp->prev->n /= tmp->n;
		tmp->prev->next = NULL;
	}
	else
	{
		if (tmp->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			free(ALL.line);
			fclose(ALL.file);
			free_list(*stack);
			exit(EXIT_FAILURE);
		}
		tmp->next->n /= tmp->n;
		*stack = tmp->next;
	}
	free(tmp);
}
