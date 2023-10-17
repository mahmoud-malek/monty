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
