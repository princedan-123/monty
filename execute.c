#include "monty.h"

/**
 * table - an array of struct containing op string and corresponding operation
 * @op: op string that determines the operation
 * Return: nothing is returned
 */

#define size 7
void optable(char *op, unsigned int line_number, stack_t **stack)
{
	int i = 0;
	instruction_t table[size] = {
		{"push", push}, {"pall", pall}, {"pop", pop},
	       	{"add", add}, {"pint", pint}, {"swap", swap},{"nop", nop}};

	while (i < size)
	{
		if (strcmp(op, table[i].opcode) == 0)
		{
			table[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (i == size)
	{
		printf("%s\n", op);
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		_free(stack);
		exit(EXIT_FAILURE);
	}

}
