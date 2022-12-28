#include "monty.h"

/**
 * main - main function for monty
 * @argc: argument count
 * @argv: argument variable
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *location = NULL;
	size_t n = 0;
	ssize_t line_read = 1;
	char *delim = "\n ", *str_val;
	/*stack_t *head = NULL;*/

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
		line_read = getline(&location, &n, file);
		if (line_read > 0)
		{
			printf("%s", location);
			str_val = strtok(location, delim);
			while (str_val != NULL)
			{
				printf("%s\n", str_val);
				str_val = strtok(NULL, delim);
			}
		}
	}

	return (0);
}
