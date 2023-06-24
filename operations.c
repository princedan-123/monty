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
	int flag = 0, integer, len, i = 0;

	if (data == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	len = strlen(data);

	while (i < len)
	{
		if ((data[i] >= '0') && (data[i] <= '9'))
			i++;
		else
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	integer = atoi(data);
	new->n = integer;
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
		fprintf(stdout, "%i\n", tmp->n);
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

	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(*stack);
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

	if ((current == NULL) || (current->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	sum += tmp->n;
	sum += tmp->next->n;
	tmp->next->n = sum;
	tmp = tmp->next;
	tmp->prev = NULL;
	free(current);
	*stack = tmp;
}
/**
 * multiply - multiply the first two top nodes
 * @stack: a pointer to pointer that points to the top of the stack
 * @line_number: the line number of the monty byte code
 * Return: nothing is returned
 */

void multiply(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *tmp = *stack;
	int mul = 0;

	if ((current == NULL) || (current->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(stack);
		exit(EXIT_FAILURE);
	}
	mul = tmp->n;
	mul *= tmp->next->n;
	tmp->next->n = mul;
	tmp = tmp->next;
	tmp->prev = NULL;
	free(current);
	*stack = tmp;
}
