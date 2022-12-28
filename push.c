#include "monty.h"

/**
 * push - pushes an element to the stack
 * @head - the head of the stack
 * @number - the element added to the stack
 * Return: the head of the stack
 */

stack_t *pushf(stack_t *head, unsigned int number)
{
	if (*head == NULL)
	{
		*head = malloc_me();

		(*head)->n = number;
		(*head)->prev = NULL;
		(*head)->next = NULL;
	}

	else
	{
		stack_t *new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			dprintf(3, "Error: malloc failed");
			exit(EXIT_FAILURE);
		}

		new->n = number;
		new->next = *head;
		new->prev = NULL;
		*head = new;
	}
	return (*head);
}
