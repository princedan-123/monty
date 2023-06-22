#include "monty.h"
int data = 0;
int main(int argc, char *argv[])
{
	char *opcode = NULL, *argument = NULL;
	FILE *ptr = NULL;
	unsigned int line_number = 0;
	char buffer[150];

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
		opcode = strtok(buffer, " ");
		argument = strtok(NULL, " ");
		line_number++;
		if (opcode == NULL || opcode[0] == '\n')
			continue;

		if (argument != NULL)
			data = atoi(argument);

		optable(opcode, line_number);
	}
	fclose(ptr);
	return (0);

}
