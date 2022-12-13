#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define bool int
#define true 1
#define false 0
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void push(stack_t **head, unsigned int line_no, char *pa, bool stat);
void pall(stack_t **head, unsigned int line_no);
void pint(stack_t **head, unsigned int line_no);
void pop(stack_t **head, unsigned int line_no);
void swap(stack_t **head, unsigned int line_no);
void add(stack_t **head, unsigned int line_no);
void nop(stack_t **head, unsigned int line_no);
void sub(stack_t **head, unsigned int line_no);
void _div(stack_t **head, unsigned int line_no);
void mul(stack_t **head, unsigned int line_no);
void mod(stack_t **head, unsigned int line_no);
void pchar(stack_t **head, unsigned int line_no);
void pstr(stack_t **head, unsigned int line_no);
void rotr(stack_t **head, unsigned int line_no);
void stack(stack_t **head, unsigned int line_no);
void queue(stack_t **head, unsigned int line_no);

#endif /* MONTY_H */

