#include "monty.h"
/**
  * really_number - verifies that the string is really a number
  * @number: string to be verified
  * Return: a flag to catch an error
  */
int really_number(char *number)
{
	int c = 0;
	int flag = 1;

	while (number[c] != '\0')
	{
		if ((number[c] < 48 || number[c] > 57) && number[c] != '-')
		{
			flag = 0;
			return (flag);
		}
		c++;
	}
	return (flag);
}
/**
  * push_error_handler - handles the errors for push func
  * @stack: a stack to be freed if needed
  * @tokenized: string to compare
  * @line: the line to print if error ocurred
  */
void push_error_handler(stack_t *stack, char *tokenized, unsigned int line, FILE *fp)
{
	stack = stack;
	if (tokenized && really_number(tokenized))
	{
		global_variable = atoi(tokenized);
		if (global_variable == 0 && strcmp(tokenized, "0"))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			free_stack(stack);
			free(tokenized);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
	}
        else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free_stack(stack);
		free(tokenized);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

