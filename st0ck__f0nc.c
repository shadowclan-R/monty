#include "monty.h"

/**
 * add__to__stack - Adds a new node to the top of the stack
 * @new_node: Pointer to the new node to be added
 * @ln: Line number (unused)
 */
void add__to__stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;
	stack_t *head = NULL;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}


/**
 * print__stack - Prints all the elements of a stack
 * @stack: A pointer to the top of the stack
 * @line_number: The line number (unused in this function)
 */
void print__stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop__top - Removes the top element of a stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the current operation.
 */
void pop__top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more__err(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print__top - Prints the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the source file.
 */
void print__top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more__err(6, line_number);
	printf("%d\n", (*stack)->n);
}
