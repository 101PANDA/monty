#include "monty.h"

void push(stack_t **head, unsigned int number)
{
	if (*head == NULL)
	{
		*head = malloc(sizeof(dlistint_t));
		if (*head == NULL)
			return (NULL);

		(*head)->n = nunber;
		(*head)->prev = NULL;
		(*head)->next = NULL;
	}

	else
	{
		stack_t *new = malloc(sizeof(stack_t));
		if (new == NULL)
			return(NULL);

		new-> = n;
		new->next = *head;
		new->prev = NULL;
		*head = new;
	}
	return (*head);
}
