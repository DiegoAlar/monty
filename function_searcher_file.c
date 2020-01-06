#include "monty.h"

/**
  * eArr - evaluates case no command found in array
  * @st: double pointer of the stack
  * @ln: number of the line to print error
  * @c: counter of the array
  * @tok: command to see if in array
  * @fp: file descriptor if in need to be closed
  * @le: line from getline to be freed
  */
void eArr(stack_t **st, unsigned int *ln, int c, char **tk, FILE *fp, char *le)
{
	if (c == 13)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", *ln, *tk);
		free_stack(*st);
		free(le);
		fclose(fp);
		exit(EXIT_FAILURE);
	}
}

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
		{"sub", sub	},
		{"div", divide	},
		{"mul", multiply},
		{"mod", module	},
		{"pchar", print_char_fn},
		{"pstr", print_chars_fn}
	};
	while (count < 13 && *tok != NULL)
	{
		if (*tok[0] == '#')
			break;
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
	eArr(stack, ln, count, tok, fp, ln_f);
	*ln = *ln + 1;
}
