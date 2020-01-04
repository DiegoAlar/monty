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
	int read;
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
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("heyyyyyyyyyyy: %d\n", read);
		tokenized = strtok(line, delim);

		while (count < 5 && tokenized != NULL)
		{
			/*printf("array: %s -- token: %s\n", st_funcs[count].opcode, tokenized);*/
			if (!strcmp((st_funcs[count].opcode), tokenized))
			{
				printf("111\n");
				tokenized = strtok(NULL, delim);
				printf("2222222\n");
				if (!tokenized)
					printf("is null\n");
				if (!strcmp(st_funcs[count].opcode, "push"))
				{
					if (tokenized)
						global_variable = atoi(tokenized);
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", read);
						exit(EXIT_FAILURE);
					}
				}
				st_funcs[count].f(&stack, read);
				break;
			}
			count++;
		}
		count = 0;
	}
	return (EXIT_SUCCESS);
}
