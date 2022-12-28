#include "monty.h"
/**
 * func_select - function pointer that selects the correct function to perform
 * @cmd: the command given by the user
 * Return: returns pointer to the function that corresponds
 * or null if none is found
 */

void (*func_select(char *cmd))(stack_t **, unsigned int)
{
	instruction_t  cmds[] = {
		{"push", pushf},
		{"pall", pallf},
		{NULL, NULL}
	};
	int i = 0;

	while(cmds[i].opcode)
	{
		if (strcmp(cmds[i].opcode, cmd) == 0)
			return (cmds[i].f);
		i++;
	}

	return (NULL);
}
