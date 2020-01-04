#include "monty.h"
int global_variable = 0;
/**
  * main - main function
  * @argc - number of elements as arguments
  * @argv - array with argument elements
  */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *fp;
	unsigned int error_line = 1;
	char *line = NULL;
	size_t len = 0;
	char *tokenized = NULL;
	int count = 0;
	char *delim = " \n";

	instruction_t st_funcs[] = {
		{"push", push	},
		{"pall", pall	},
		{"pint", pint	},
		{"pop", pop	},
		{"swap", swap	}
	};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		tokenized = strtok(line, delim);

		while (count < 5 && tokenized != NULL)
		{
			if (!strcmp((st_funcs[count].opcode), tokenized))
			{
				tokenized = strtok(NULL, delim);
				if (!strcmp(st_funcs[count].opcode, "push"))
					push_error_handler(stack, tokenized, error_line);
				st_funcs[count].f(&stack, error_line);
				break;
			}
			count++;
		}
		error_line++;
		count = 0;
	}
	return (EXIT_SUCCESS);
}
