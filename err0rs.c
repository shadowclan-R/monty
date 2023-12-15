#include "monty.h"

/**
 * err - Prints_appropiate_error_messages_determined_by-their error code.
 * @error__code: The error codes are the following:
 * (1) => The user_does-not_give_any_file or more than one file to the program.
 * (2) => The file_provided_is_not a file that can be opened or read.
 * (3) => The file_provided_contains an invalid instruction.
 * (4) => When the_program_is_unable to malloc more memory.
 * (5) => When the_parameter_passed to the instruction "push" is not an int.
 * (6) => When the_stack it empty for pint.
 * (7) => When the_stack it empty for pop.
 * (8) => When stack_is too short for operation.
 */
void err(int error__code, ...)
{
	va_list ag;
	char *op;
	int l__num;

	va_start(ag, error__code);
	switch (error__code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l__num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l__num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free__nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the_stack it empty for pint.
 * (7) => When the_stack it empty for pop.
 * (8) => When_stack is too short for operation.
 * (9) => Division_by_zero.
 */
void more__err(int error__code, ...)
{
	va_list ag;
	char *op;
	int l__num;

	va_start(ag, error__code);
	switch (error__code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l__num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l__num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free__nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handles_errors.
 * @error_code: The error_codes_are the following:
 * (10) ~> The number_inside_a_node is outside ASCII bounds.
 * (11) ~> The stack_is_empty.
 */
void string__err(int error__code, ...)
{
	va_list ag;
	int l__num;

	va_start(ag, error__code);
	l__num = va_arg(ag, int);
	switch (error__code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l__num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l__num);
			break;
		default:
			break;
	}
	free__nodes();
	exit(EXIT_FAILURE);
}