#include "monty.h"
/**
 * op_nop - does nothing
 *
 * @head: the stack
 * @line_no: the line_number
 * Return: nothing, it is void
 */
void op_nop(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;
}
/**
 * op_pchar prints ascii
 *
 * @head: the stack
 * @line_no: the line_number
 * Return: nothing, it is void
 */
void op_pchar(stack_t **head, unsigned int line_no)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "%ld: can't pchar, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 32 || (*head)->n > 126)
	{
		fprintf(stderr, "%ld: can't pchar, value out of range\n", line_no);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c", (*head)->n);
}
/**
 * op_pstr - prints the ascii value in the stack'
 *
 * @head: the head
 * @line_no: the line_number
 * Return: nothing, it was void
 */
void op_pstr(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	(void)line_no;

	temp = (*head);
	while (temp)
	{
		if (temp->n < 32 || temp->n > 126)
			break;
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
/**
 * op_rotl - rotates top to bottom
 *
 * @head: the stack
 * @line_no: the line number
 * Return: nothing, it is void
 */
void op_rotl(stack_t **head, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*head) && (*head)->next)
	{

		top = (*head);
		bottom = (*head)->next;
		while (bottom->next)
			bottom = bottom->next;
		(*head) = (*head)->next;
		bottom->next = top;
		top->next = NULL;
		top->prev = bottom;
		(void)line_no;

	}
}
/**
 * op_rotr - rotates the bottom to the top
 *
 * @head: the stack
 * @line_no: the line number
 */
void op_rotr(stack_t **head, unsigned int line_no)
{
	stack_t *top, *bottom;

	if ((*head) && (*head)->next)
	{
		top = (*head)->next;
		bottom = (*head)->next;
		while (bottom->next)
			bottom = bottom->next;
		bottom->prev->next = NULL;
		(*head)->next = bottom;
		bottom->prev = (*head);
		bottom->next = top;
		top->prev = bottom;
		(void)line_no;
	}
}
