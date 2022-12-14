#include "monty.h"
/**
 * main - the main runner of the code
 *
 * @ac: the number of command line arguments
 * @av: the array of command line arguments
 * Return: success
 */

int main(int ac, char *av[])
{
	stack_t *h = NULL;
	char **arguments, **result;
	size_t i;
	void (*func)(stack_t **, unsigned int);
	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	arguments = split(pen(av[1]), "\n", 0);
	i = 0;
	while (arguments[i])
	{
		result = split(arguments[i], " ", 0);
		if (strcmp(result[0], "push") == 0)
			push(&h, i, result[1]);
		else
		{
			func = get_opcode(result[0]);
			if (func == NULL)
			{
				break;
				fprintf(stderr, "%ld: unknown intruction: %s\n", i, result[0]);
				exit(EXIT_FAILURE);
			}
			func(&h, i);
		}
		i++;
		free(result);
	}
	free_stack(h);
	free(arguments);
	return (0);
}
