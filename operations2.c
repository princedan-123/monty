#include "monty.h"

/**
 * pint - print the value at the top of the stack
 * @stack: double pointer to top of stack
 * @line_number: line number where function occurs
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * swap - swaps the top two values in a stack
 * @stack: double pointer to top of stack
 * @line_number: line number where function occurs
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp = (*stack)->n;

	if (stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * nop - does nothing
 * @stack: double pointer to the top of the stack
 * @line_number: line number where function occurs
 *
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
