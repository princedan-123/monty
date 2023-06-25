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
		_free(stack);
		exit(EXIT_FAILURE);
	}
	mod = tmp->next->n;
	mod = mod % tmp->n;
	tmp->next->n = mod;
	tmp = tmp->next;
	tmp->prev = NULL;
	free(current);
	*stack = tmp;
}

/**
 * pchar -  prints the char at the top of the stack, followed by a new line
 * @stack: double pointer to top of stack
 * @line_number: line number where function is called
 *
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int val = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}

	if (val < 0 || val > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", val);
}

/**
 * pstr -  prints the string starting at the top, followed by new line
 * @stack: double pointer to the top of the stack
 * @line_number: line number where function is called
 *
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *val= *stack;
	(void)line_number;


	while (val != NULL && val->n != 0 && (val->n >= 0 && val->n <= 127))
	{
		putchar(val->n);
		val = val->next;
	}
	putchar('\n');

}

/**
 * rot1 - rotates the stack to the top
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 *
 * Return: always void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *val = *stack;
	(void)line_number;

	if (val == NULL || val->next == NULL)
		return;

	while (val->next != NULL)
		val = val->next;

	val->next = *stack;
	*stack = (*stack)->next;
	val->next->prev = NULL;
	val->next->next = NULL;
}
