#include "monty.h"
/**
  * main - main function
  * @argc: number of elements as arguments
  * @argv: array with argument elements
  * Return: Exit_success when succeded, otherwise failure
  */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *fp;
	unsigned int error_line = 1;
	char *line = NULL;
	size_t len = 0;
	char *tokenized = NULL;
	char *delim = " \n\t";

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		tokenized = strtok(line, delim);
		fn_s(&stack, &tokenized, &error_line, fp, line);
	}
	free_stack(stack);
	free(line);
	if (fclose(fp) == -1)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
