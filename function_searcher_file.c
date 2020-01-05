#include "monty.h"
/**
  * fn_s - searches a function given a struct
  * @stack: the head of the stack
  * @tok: the string to compare with the struct
  * @ln: currently line of .m file
  * @fp: file descriptor to be closed
  * @ln_f: line from getline to be freed
  */
void fn_s(stack_t **stack, char **tok, unsigned int *ln, FILE *fp, char *ln_f)
{
	int count = 0;
	char *delim = " \n\t";

	instruction_t st_funcs[] = {
		{"push", push   },
		{"pall", pall   },
		{"pint", pint   },
		{"pop", pop     },
		{"swap", swap   },
		{"add", add	},
		{"nop", nop	},
		{"sub", sub	}
	};
	while (count < 8 && *tok != NULL)
	{
		if (!strcmp((st_funcs[count].opcode), *tok))
		{

			*tok = strtok(NULL, delim);
			if (!strcmp(st_funcs[count].opcode, "push"))
			{
				p_err(*stack, tok, *ln, fp, ln_f);
			}
			st_funcs[count].f(stack, *ln);
			break;
		}
		count++;
	}
	if (count == 8)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", *ln, *tok);
		free_stack(*stack);
		free(ln_f);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	*ln = *ln + 1;
}
