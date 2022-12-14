#include "monty.h"
/**
 * op_add - adds the first and second element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_add(stack_t **head, unsigned int line_no)
{
	stack_s *temp;
	int a;

	temp = (*head);
	if (!(temp && temp->next))
	{
                fprintf(stderr, "%ld: can't add, stack too short\n", line_no);
                exit(EXIT_FAILURE)
	}
	a = temp->n + temp->next->n;
	(*head)->next->n = a;
	(*head) = (*head->next);
	free(temp);
}
/**
 * op_sub - subtracts the first from the second element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_sub(stack_t **head, unsigned int line_no)
{                                                                  stack_s *temp;
        int a;

        temp = (*head);
        if (!(temp && temp->next))                                 {                                                                  fprintf(stderr, "%ld: can't add, stack too short\n", line_no);
                exit(EXIT_FAILURE)
        }
        a = temp->next->n - temp->n;
        (*head)->next->n = a;
        (*head) = (*head->next);
        free(temp);
}
/**
 * op_mul - multiplies the first and second element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_mul(stack_t **head, unsigned int line_no)
{                                                                  stack_s *temp;
        int a;

        temp = (*head);
        if (!(temp && temp->next))                                 {                                                                  fprintf(stderr, "%ld: can't add, stack too short\n", line_no);
                exit(EXIT_FAILURE)
        }
        a = temp->n * temp->next->n;
        (*head)->next->n = a;
        (*head) = (*head->next);
        free(temp);
}
/**
 * op_div - divides the second by thr first element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_div(stack_t **head, unsigned int line_no)
{                                                                  stack_s *temp;
        int a;

        temp = (*head);
        if (!(temp && temp->next))                                 {                                                                  fprintf(stderr, "%ld: can't add, stack too short\n", line_no);
                exit(EXIT_FAILURE)
        }
	if (temp->n == 0)
	{
		fprintf(stderr, "%ld: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}
        a = temp->next->n / temp->n;
        (*head)->next->n = a;
        (*head) = (*head->next);
        free(temp);
}
/**
 * op_mod - gives the modulus of the second by the first element in the stack
 *
 * @head: the head of the stack
 * @line_no: the line number
 * Return: Nothing, it is void
 */
void op_mod(stack_t **head, unsigned int line_no)
{                                                                  stack_s *temp;
        int a;

        temp = (*head);
        if (!(temp && temp->next))                                 {                                                                  fprintf(stderr, "%ld: can't add, stack too short\n", line_no);
                exit(EXIT_FAILURE);
        }
	if (temp->n == 0)
	{
		fprintf(stderr, "%ld: division by zero\n", line_no);
		exit(EXIT_FAILURE);
	}
        a = temp->next->n % temp->n;
        (*head)->next->n = a;
        (*head) = (*head->next);
        free(temp);
}