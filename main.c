#include "monty.h"

/**
 * main - main function for monty
 * @argc: argument count
 * @argv: argument variable
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	ssize_t line_read = 1;
	char *location = NULL;
	char *delim = " \n", *str_val = NULL;
	void (*operation)(stack_t **, unsigned int);
	int i;
	FILE *file;
	size_t n = 0;
	stack_t *head = malloc_me();

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_read > 0)
	{
		i = 1;
		line_read = getline(&location, &n, file);
		if (line_read > 0)
		{
			str_val = strtok(location, delim);
			while (str_val != NULL)
			{
				if (i == 1)
				{
					strcpy(cmd, str_val);
					operation = func_select(str_val);
					str_val = strtok(NULL, delim);
					i++;
				}
				else
				{
					i = atoi(str_val);
					if (strcmp(cmd, "push") == 0)
						head = operation(&head, i);
					else
						operation(&head, i);
					i = 1;
				}
			}
		}
	}

	return (0);
}

stack_t *malloc_me(void)
{
	stack_t *space = malloc(sizeof(stack_t));
	if (space == NULL)
	{
		dprintf(3, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	return (space);
}
