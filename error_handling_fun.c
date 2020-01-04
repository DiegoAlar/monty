#include "monty.h"
/**
  * push_error_handler - handles the errors for push func
  * @stack: a stack to be freed if needed
  * @tokenized: string to compare
  * @line: the line to print if error ocurred
  */
void push_error_handler(stack_t *stack, char *tokenized, unsigned int line)
{
	stack = stack;
	if (tokenized)
	{
		global_variable = atoi(tokenized);
		if (global_variable == 0 && strcmp(tokenized, "0"))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
        else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
}

