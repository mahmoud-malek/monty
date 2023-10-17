#include "monty.h"

/**
 * delete_node_beginning - Deletes a node at the beginning of the list.
 * @head: Double pointer to the head of the list.
 *
 * Return: Nothing.
 */
void delete_node_beginning(stack_t **head)
{
	stack_t *temp;

	if (*head == NULL)
		return;

	temp = *head;
	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;

	free(temp);
}

/**
 * delete_node_end - Deletes a node at the end of the list.
 * @head: Double pointer to the head of the list.
 *
 * Return: Nothing.
 */
void delete_node_end(stack_t **head)
{
	stack_t *temp, *last = *head;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	temp = last;
	last = last->prev;
	last->next = NULL;

	free(temp);
}

/**
 * _isdigit - Checks if a string is a number.
 * @str: The string to check.
 *
 * This function checks if a given string is a number. It allows for a negative
 * sign at the beginning of the string. If the string is NULL,
 *  or if it contains
 * any characters that are not digits
 * (or a negative sign at the beginning), the
 * function will return 1. Otherwise, it will return 0.
 *
 * Return: 0 if the string is a number, 1 otherwise.
 */

int _isdigit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);

	if (str[0] == '-')
		i = 1;

	for (; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}

	return (0);
}
