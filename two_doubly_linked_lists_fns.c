#include "monty.h"
/**
  * add - adds top 2 elements of stack
  * @stack: pointer to the head of stack
  * @line_number: number of line monty is currently reading
  *
  */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}
void nop(stack_t **stack, unsigned int line_number)
{
	line_number = line_number;
	*stack = *stack;
}
/**
  * add - adds top 2 elements of stack
  * @stack: pointer to the head of stack
  * @line_number: number of line monty is currently reading
  *
  */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}

