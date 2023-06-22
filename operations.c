#include "monty.h"

/**
 * push - inserts a node into a stack via linked list
 * @stack:a pointer to a pointer to the top of the stack
 * @line_number: line number of monty file
 * return: nothing is returned
 */

void push(stack_t **stack, unsigned int line_number)
{	
	stack_t *new = malloc(sizeof(stack_t));

	(void)line_number;
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n =  data;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * pall - prints the data in the stack
 * @stack:  pointer to a pointer to the top of the stack
 * @line_number: the current line number
 * Return: nothing is returned
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack == NULL)
		exit(0);

	while (tmp != NULL)
	{
		fprintf(stdout, "%i", tmp->n);
			tmp = tmp->next;
	}
}
/**
 * pop - deletes the top node in a stack
 * @stack: a pointer to a pointer to the top stack
 * @line_number: the line number of the monty file
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (tmp == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
	if (tmp->next != NULL)
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
	free(tmp);
}
/**
 * add - adds the first two top nodes
 * @stack: a pointer to pointer that points to the top of the stack
 * @line_number: the line number of the monty byte code
 * Return: nothing is returned
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *tmp = *stack;
	int sum = 0;
	(void)line_number;

	if ((current == NULL) || (current->next == NULL))
	{
		fprintf(stderr, "L<line_number>: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
	while (tmp != NULL)
	{
		sum = tmp->n;
		tmp = tmp->next;
		break;
	}
	tmp->n += sum;
	tmp->prev = NULL;
	free(current);
}
