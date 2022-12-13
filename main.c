#include "monty.h"
int main(void)
{
	stack_t *h = NULL;

	push(&h, 1, "1", true);

	push(&h, 2, "2", true);
	push(&h, 3, "3", true);
	pall(&h, 4);
	swap(&h, 5);
	pall(&h, 6);
       
	return (0);

}
