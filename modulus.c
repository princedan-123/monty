#include "monty.h"
/**
 * modulus - find the remainder of first two top nodes
 * @stack: a pointer to pointer that points to the top of the stack
 * @line_number: the line number of the monty byte code
 * Return: nothing is returned
 */

void modulus(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *tmp = *stack;
	int mod = 0;

	if ((current == NULL) || (current->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
	}
	mod = tmp->n;
	mod = tmp->next->n % mod;
	tmp->next->n = mod;
	tmp = tmp->next;
	tmp->prev = NULL;
	free(current);
	*stack = tmp;
}
