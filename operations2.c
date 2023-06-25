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
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		_free(stack);
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

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", line_number);
		_free(stack);
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

/**
 * sub - subtracts the two top stack
 * @stack: the pointer to the top of the stack
 * @line_number: the line number of the monty bytecode
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *tmp = *stack;
	int minus = 0;

	if ((current == NULL) || (current->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	minus = tmp->next->n;
	minus -= tmp->n;
	tmp->next->n = minus;
	tmp = tmp->next;
	tmp->prev = NULL;
	free(current);
	*stack = tmp;
}
/**
 * divide - adds the first two top nodes
 * @stack: a pointer to pointer that points to the top of the stack
 * @line_number: the line number of the monty byte code
 * Return: nothing is returned
 */

void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *tmp = *stack;
	int div = 0;

	if ((current == NULL) || (current->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	div = tmp->next->n;
	div = div / tmp->n;
	tmp->next->n = div;
	tmp = tmp->next;
	tmp->prev = NULL;
	free(current);
	*stack = tmp;
}
