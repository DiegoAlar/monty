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

	if (stack_t == NULL)
		return (NULL);
	newN = malloc(sizeof(stack_t));
	if (!newN)
		return (NULL);
	if (*stack == NULL)
	{
		newN->n = n;
		newN->prev = NULL;
		newN->next = NULL;
		*stack = newN;
	}
	else
	{

		if ((*stack)->prev == NULL)
		{
			newN->n = n;
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
	while (*h)
	{
		printf("%d\n", *(h)->n);
		*h = *(h)->next;
	}
}
/**
  * pint - prints the value at the top of the stack
  * @h: the list
  * @line_number: line number
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", *(stack)->n);
}
/**
  * pop - for cases of index eq to zero
  * @head: pointer to head of list
  * @line_number: line number
  */
void pop(stack_t **stack, unsigned int line_number)
{

	char *mse_err_0 = "L";
	char *mge_err_1 = ": can't pop an empty stack\n";
	if (stack || *stack)
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
		write(STDERR_FILENO, "L", 1);
		write(STDERR_FILENO, itoa(line_number), strlen(itoa(line_number)));
		write(STDERR_FILENO, mge_err_1, strlen(mge_err_1));
		fprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
	}
}
/**
  * swap - swap two elements of the list 
  * @stack: pointer to head of list
  * @line_number: line number
  */
/*void swap(stack_t **stack, unsigned int line_number)
{
	
}*/

