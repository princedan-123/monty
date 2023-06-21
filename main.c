#include "monty.h"
int data = 0;
int main(int argc, char *argv[])
{
	char *buffer = NULL, *opcode = NULL, *argument = NULL;
	size_t size = 0;
	FILE *ptr = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
		exit(EXIT_FAILURE);
	ptr = fopen(argv[1], "r");
	if (ptr == NULL)
	{
		printf("error");
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, ptr) != 1)
	{
		opcode = strtok(buffer, " ");
		argument = strtok(NULL, " ");
		line_number++;
		data = atoi(argument);
		optable(opcode, line_number);
	}
	fclose(ptr);
	return (0);

}
