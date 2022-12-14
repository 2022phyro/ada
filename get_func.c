#include "monty.h"
/**
 * get_opcode - gets the opcode of a particular function
 *
 * @s: the opcode to be checked
 * Return: a function pointer to the right opcode
 */
void (*get_opcode(char *s))(stack_t **, unsigned int)
{
	instruction_t op[] = {
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"pint", op_pint},
		{"add", op_add},
		{"sub", op_sub},
		{"mul", op_mul},
		{"div", op_div},
		{"mod", op_mod},
		{"nop", op_nop},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{NULL, NULL}
	};
	int i;

	i = 0;
	if (s[0] == '#')
		return (op[9].f);
	while (i < 14)
	{
		if (strcmp(s, op[i].opcode) == 0)
			return (op[i].f);
		i++;
	}
	return (op[9].f);

}
/**
 * free_str - free a string
 *
 * @s: the array of strings to be freed
 * Return: nothing, it is void
 */
void free_str(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s[i]);

}
/**
 * free_stack - frees a stack
 *
 * @h: the head of the stack
 * Return: nothing it is void
 */
void free_stack(stack_t *h)
{
	stack_t *temp;

	while (h)
	{
		temp = h;
		h = h->next;
		free(temp);
	}
	free(h);
}
/**
 * asci - checks if a character is ascii
 *
 * @s: the number
 * Return: true or false
 */
int asci(int n)
{
	if (n < 32 || n > 126)
		return (0);
	return (1);
}
