#include "monty.h"

/**
 * myrotr - Rotates the stack to the bottom.
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * The last element of the stack becomes the top one,
 * and the second last element becomes the last one.
 */
void myrotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		*stack = tmp;
	}
}

/**
 * mystack - Sets the format of the data to a stack (LIFO).
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * Description: This function sets a global flag (ALL.stack) to 1,
 * indicating that the data structure should behave as a stack.
 */

void mystack(stack_t **stack, unsigned int line_number)
{
	ALL.stack = 1;
	(void)line_number;
	(void)stack;
}

/**
 * myqueue - Sets the format of the data to a queue (FIFO).
 * @stack: A double pointer to the beginning of the stack.
 * @line_number: The line number where the instruction was found.
 *
 * Description: This function sets a global flag (ALL.stack) to 0,
 * indicating that the data structure should behave as a queue.
 */

void myqueue(stack_t **stack, unsigned int line_number)
{
	ALL.stack = 0;
	(void)line_number;
	(void)stack;
}
