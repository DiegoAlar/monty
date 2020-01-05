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
  * p_err - handles the errors for push func
  * @stack: a stack to be freed if needed
  * @tok: string to compare
  * @ln: the line to print if error ocurred
  * @fp: the file to be closed
  * @ln_f: string from getline to be freed
  */
void p_err(stack_t *stack, char **tok, unsigned int ln, FILE *fp, char *ln_f)
{
	if (*tok && really_number(*tok))
	{
		global_variable = atoi(*tok);

		if (global_variable == 0 && strcmp(*tok, "0"))
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			free_stack(stack);
			free(ln_f);
			fclose(fp);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free_stack(stack);
		free(ln_f);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

