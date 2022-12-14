#include "monty.h"
/**
 * get_opcode - 
 */
void (*get_opcode(char *s))(stack_t **, unsigned int)
{
	instruction_t op[] = {
		{"pall", op_pall},
		{"pop", op_pop},
		{"swap", op_swap},
		{"pint", op_pint},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 4)
	{
		if (strcmp(s, op[i].opcode) == 0)
			return (op[i].f);
		i++;
	}
	return (NULL);

}
