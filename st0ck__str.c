#include "monty.h"

/**
 * print__char - Prints the ASCII character at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the source file where print_char.
 */
void print__char(stack_t **stack, unsigned int line_number)
{
	int asi;

	if (stack == NULL || *stack == NULL)
		string__err(11, line_number);

	asi = (*stack)->n;
	if (asi < 0 || asi > 127)
		string__err(10, line_number);
	printf("%c\n", asi);
}

/**
 * print__str - prints the ASCII values of elements in a stack
 * @stack: double pointer to the stack
 * @ln: unused parameter (line number)
 */
void print__str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asi;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		asi = temp->n;
		if (asi <= 0 || asi > 127)
			break;
		printf("%c", asi);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the top of the stack.
 * @ln: Line number (unused).
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the top of the stack.
 * @ln: Line number (unused).
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
