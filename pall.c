#include "monty.h"

/**
 * print_dlistint - print all elements on a list
 * @h: head of the list
 * Return: number of list
 */

void pallf(stack_t **head, unsigned int number)
{
	int n_nodes = 0;
	UNUSED(number);

	while (head != NULL)
	{
		printf("%d\n", (*head)->n);
		(*head) = (*head)->next;
		n_nodes++;
	}
}
