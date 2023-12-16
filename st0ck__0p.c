#include "monty.h"

/**
 * mul__nodes - Multiplies the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the script where the instruction appears.
 */
void mul__nodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more__err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod__nodes - Computes the modulo of the top two nodes of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the source file where the operation.
 */
void mod__nodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more__err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more__err(9, line_number);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
