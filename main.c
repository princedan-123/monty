#include "monty.h"
char *data = NULL;
/**
 * main - entry point
 * @argc: count of command line
 * @argv: array of command line arguments
 * Return: zero
 */

int main(int argc, char *argv[])
{
	char *opcode = NULL, *argument = NULL;
	FILE *ptr = NULL;
	unsigned int line_number = 1;
	char buffer[150];
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ptr = fopen(argv[1], "r");
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(buffer, sizeof(buffer), ptr) != NULL))
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		opcode = strtok(buffer, " ");
		argument = strtok(NULL, " ");
		if (opcode == NULL || opcode[0] == '\n')
			continue;
		data = argument;
		optable(opcode, line_number, &stack);
		line_number++;
	}
	fclose(ptr);
	return (0);

}
