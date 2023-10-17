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

