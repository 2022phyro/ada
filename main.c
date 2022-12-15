#include "monty.h"
/**
 * cleanup - frees everything
 *
 * @h: the stack
 * @ag: the argument
 * @s: the opcodes
 * @st: the file
 * Return: nothing, it is voi
 */
void cleanup(stack_t *h, char **ag, char **s, char *st)
{
	int j;

	j = wer("record");
	if (j == 0)
	{
		free_stack(h);
		free(ag);
		free(s);
		free(st);
		exit(EXIT_FAILURE);
	}
	else
		return;
}
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
	char **arguments, **result, *string;
	size_t i = 0;
	void (*func)(stack_t **, unsigned int);

	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	string = pen(av[1]);
	arguments = split(string, "\n", 0);
	while (arguments[i])
	{
		result = split(arguments[i], " ", 0);
		if (strcmp(result[0], "push") == 0)
		{
			push(&h, i + 1, result[1]);
			cleanup(h, arguments, result, string);
		}
		else
		{
			if (check(result[0]) == 0)
			{
				fprintf(stderr, "%ld: unknown intruction %s\n", i + 1, result[0]);
				free(result);
				cleanup(h, arguments, result, string);
				break;
			}
			func = get_opcode(result[0]);
			func(&h, i + 1);
			cleanup(h, arguments, result, string);
		}
		i++;
		free(result);
	}
	free_stack(h);
	free(arguments);
	free(string);
	return (EXIT_SUCCESS);
}
