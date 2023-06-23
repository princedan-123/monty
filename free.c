#include "monty.h"

/**
 * _free -  frees a stack
 * @stack: a pointer to the top of the stack
 * Return: nothing
 */

void _free(stack_t **stack)
{
	stack_t *tmp = *stack;
	stack_t *current = *stack;

	while (tmp != NULL)
	{
		current = tmp;
		tmp = tmp->next;
		free(current);
	}
}
