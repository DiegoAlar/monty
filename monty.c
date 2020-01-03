#include "monty.h"
/**
  * main - main function
  * @argc - number of elements as arguments
  * @argv - array with argument elements
  */
int main(argc, *argv)
{
	stack_t *stack = NULL;
	FILE *fp;
	unsigned int read;
	char *line = NULL;
	size_t len = 0;
	char *tokenized = NULL;
	int cont = 0;
	char delim = ' ';

	stack_t st_funcs[] = {
		{"push", push	},
		{"pall", pall	},
		{"pint", pint	},
		{"pop", pop	},
		{"swap", swap	}
	};
	
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		/*call funct to tokenize line */
		tokenized = strtok(line, delim);

		while (cont < 5 && tokenized != NULL)
		{
			if (!strcmp((st_funcs[count].opcode, tokenized[0])))
			{
				tokenized = strtok(NULL, delim);
				global_variable = atoi(tokenized);
				st_funcs[count].f(&stack, read);

			}
			cont++;
		}
		cont = 0;
	}
	return (EXIT_SUCCESS);
}
