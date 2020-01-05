#include "monty.h"
/**
  * func_searcher - searches a function given a struct
  * @stack: the head of the stack
  * @token: the string to compare with the struct
  *
  */
void func_searcher(stack_t **stack, char *token, unsigned int *line, FILE *fp)
{
	int count = 0;
	char *delim = " \n";

	instruction_t st_funcs[] = {
		{"push", push   },
		{"pall", pall   },
		{"pint", pint   },
		{"pop", pop     },
		{"swap", swap   }
	};
	while (count < 5 && token != NULL)
	{
		if (!strcmp((st_funcs[count].opcode), token))
		{
			token = strtok(NULL, delim);
			if (!strcmp(st_funcs[count].opcode, "push"))
			{
				push_error_handler(*stack, token, *line, fp);
			}
			st_funcs[count].f(stack, *line);
			break;
		}
		count++;
	}
	if (count == 5)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *line, token);
		free_stack(*stack);
		free(token);
		exit(EXIT_FAILURE);		
	}
	*line = *line + 1;
}
