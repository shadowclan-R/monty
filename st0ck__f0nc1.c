#include "monty.h"

/**
 * nop - Nothing does.
 * @stack: A pointer to the stack, unused in this function.
 * @line_number: The line number of the opcode being executed.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap__nodes - swaps the top two elements of the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode in the file
 */
void swap__nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more__err(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add__nodes - Adds the top two nodes of the stack.
 * @stack: A pointer to the head of the stack.
 * @line_number: The line number of the opcode in the file.
 */
void add__nodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more__err(8, line_number, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub__nodes - Subtracts the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the file where the instruction appears.
 */
void sub__nodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more__err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div__nodes - Divides the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script where the operation occurs.
 */
void div__nodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more__err(8, line_number, "div");

	if ((*stack)->n == 0)
		more__err(9, line_number);
	(*stack) = (*stack)->next;
	s = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
