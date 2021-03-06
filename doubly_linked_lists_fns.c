#include "monty.h"
/**
  * push - adds a new node at the beginning of list
  * @stack: the head of the list
  * @line_number: line number
  * @n: number to be added to the new node
  */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newN;

	line_number = line_number;
	if (stack == NULL)
		return;
	newN = malloc(sizeof(stack_t));
	if (!newN)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		newN->n = global_variable;
		newN->prev = NULL;
		newN->next = NULL;
		*stack = newN;
	}
	else
	{

		if ((*stack)->prev == NULL)
		{
			newN->n = global_variable;
			newN->next = *stack;
			newN->prev = NULL;
			(*stack)->prev = newN;
			*stack = newN;

		}
	}
}
/**
  * pall - prints a double linked list
  * @stack: pointer to the stack
  * @line_number: line number
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	line_number = line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
  * pint - prints the value at the top of the stack
  * @stack: the list
  * @line_number: line number
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
  * pop - for cases of index eq to zero
  * @stack: pointer to head of list
  * @line_number: line number
  */
void pop(stack_t **stack, unsigned int line_number)
{

	if (*stack)
	{
		if ((*stack)->next)
		{
			*stack = (*stack)->next;
			free((*stack)->prev);
			(*stack)->prev = NULL;
		}
		else
		{
			free(*stack);
			*stack = NULL;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * swap - swap two elements of the list
  * @stack: pointer to head of list
  * @line_number: line number
  */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;

}

