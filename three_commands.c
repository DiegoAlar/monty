#include "monty.h"
/**
  * modulus - computes the module of two top elements
  * @stack: pointer to the head of stack
  * @line_number: number of line monty is currently reading
  *
 */
void module(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}

/**
  * print_char_fn - prints euivalent char of top stack num
  * @stack: pointer to the head of stack
  * @line_number: number of line monty is currently reading
  *
 */
void print_char_fn(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 126)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%c", (*stack)->n);
}

/**
  * print_chars_fn - prints euivalent char of top stack num
  * @stack: pointer to the head of stack
  * @line_number: number of line monty is currently reading
  *
 */
void print_chars_fn(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	line_number = line_number;
	while (temp && temp->n != 0 && (temp->n > 0 && temp->n < 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
