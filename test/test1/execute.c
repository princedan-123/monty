#include "monty.h"

/**
 * table - an array of struct containing op string and corresponding operation
 * @op: op string that determines the operation
 * Return: nothing is returned
 */

#define size 4
void optable(char *op, unsigned int line_number, stack_t **stack)
{
	int i = 0;
	instruction_t table[size] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"add", add}};

	while (i < size)
	{
		//printf("op: %s, opcode: %s\n", op, table[i].opcode);
		if (strcmp(op, table[i].opcode) == 0)
		{
			table[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (i == size)
	{
		fprintf(stderr, "L%d: unknown instruction <opcode>\n", line_number);
		//exit(EXIT_FAILURE);
	}

}
