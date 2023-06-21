#include "monty.h"

/**
 * table - an array of struct containing op string and corresponding operation
 * @op: op string that determines the operation
 * Return: nothing is returned
 */

#define size 8
void optable(char *op, unsigned int line_number)
{
	stack_t *stack = NULL;
	int i = 0;
	instruction_t table[size] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"add", add}};

	while (i < size)
	{
		if (strcmp(op, table[i].opcode) == 0)
			table[i].f(&stack, line_number);
		i++;
	}
	if (i == size)
	{
		fprintf(stderr, "L%d: unknown instruction <opcode>", line_number);
		exit(EXIT_FAILURE);
	}

}
