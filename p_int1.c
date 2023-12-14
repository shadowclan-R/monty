#include "monty.h"
/**
 * pintstack - prints the value at the top of the stack
 * @stack: double pointer stack
 * @ln_num: line number
 */
void pintstack(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp;

	(void) ln_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
