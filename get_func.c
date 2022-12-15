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
		{"push", op_push},
		{"stack", op_stack},
		{"queue", op_queue},
		{NULL, NULL}
	};
	int i;

	i = 0;
	if (s[0] == '#')
		return (op_nop);
	while (i < 17)
	{
		if (strcmp(s, op[i].opcode) == 0)
			return (op[i].f);
		i++;
	}
	return (NULL);

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
 * check - check if an argument i an opcode
 *
 * @s: the opcode
 * Return: 0 or 1
 */
int check(char *s)
{
	char *st[] = {"push", "pall", "pop", "pint", "swap",
		"add", "sub", "div", "mul", "mod", "rotl", "rotr",
		"pchar", "pstr", "stack", "queue", "nop"};
	int i, flag;

	i = 0;
	flag = 0;
	if (s[0] == '#')
		return (1);
	while (i < 17)
	{
		if (strcmp(s, st[i]) == 0)
		{
			flag = 1;
			break;
		}
		i++;
	}
	return (flag);
}
