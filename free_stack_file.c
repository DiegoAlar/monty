#include "monty.h"
/**
  * free_stack - frees a list
  * @stack: the head pointer
  */
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->prev);
	}
	free(stack);
}
