#include "monty.h"
/**
 * push - pushes an element onto the stack
 *
 * @line_no: the line number of the argument
 * @pa: the integer to be pushed
 * Return: nothing, it is void
 */

void push(stack_t **head, unsigned int line_no, char *pa)
{
	stack_t *temp;
	int n;

	if (pa == NULL)
	{
		fprintf(stderr, "%d: usage: push integer\n", line_no);
		exit(EXIT_FAILURE);
	}
	n = atoi(pa);
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error, cannot malloc");
		exit(EXIT_FAILURE);
	}
	temp->prev = NULL;
	temp->next = (*head);
	temp->n = n;
	if ((*head) != NULL)
		(*head)->prev = temp;
	(*head) = temp;
	return;
}

/**
 * op_pall - prints all values on the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: nothing, it is void
 */

void op_pall(stack_t **head, unsigned int line_no)
{
	stack_t *temp;
	(void)line_no;
       
	temp = (*head);
	while (temp)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
	return;
}

/**
 * op_pint - prints the first member of the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: nothing, it is void
 */

void op_pint(stack_t **head, unsigned int line_no)
{
	if ((*head) == NULL)
	{
		fprintf(stderr, "%d: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*head)->n);
	return;
}

/**
 * op_pop - removes the top element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line_number
 * Return: nothing, it is a void
 */

void op_pop(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	if ((*head) == NULL)
	{
		fprintf(stderr, "%d: can't pop an empty stack\n", line_no);
		exit(EXIT_FAILURE);
	}
	temp = (*head);
	(*head) = (*head)->next;
	free(temp);
	return;
}

/**
 * op_swap - swaps the top two elements in the stack
 *
 * @head: the head of the stack
 * @line_no: the line_number
 * Return: nothing, it is a void
 */

void op_swap(stack_t **head, unsigned int line_no)
{
	stack_t *temp;	
	int a;
	temp = (*head);
	if (!(temp && temp->next))
	{
		fprintf(stderr, "%d: can't swap, stack too short\n", line_no);
		exit(EXIT_FAILURE);
	}
	a = temp->n;
	temp->n = temp->next->n;
	temp->next->n = a;

	return;
}
