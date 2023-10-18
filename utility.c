#include "monty.h"

/**
 * add_node - Adds a new node to the top of the stack
 * @head: Double pointer to the head of the stack
 * @n: The integer to be added to the stack
 *
 * Return: Address of the new element, or NULL if it failed
 */

stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;

	return (new_node);
}

/**
 * add_node_end - Adds a new node to the end of the queue.
 * @head: Double pointer to the head of the queue.
 * @n: The integer to be added to the queue.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
stack_t *add_node_end(stack_t **head, const int n)
{
	stack_t *new_node, *last = *head;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	new_node->prev = last;

	return (new_node);
}

/**
 * free_list - Frees a doubly linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Nothing.
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
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
