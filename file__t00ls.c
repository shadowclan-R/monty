#include "monty.h"

/**
 * open__file-opens-a-file
 * @file__name: the-file-namepath
 * Return: void
 */

void open__file(char *file__name)
{
	FILE *f = fopen(file__name, "r");

	if (file__name == NULL || f == NULL)
		err(2, file__name);

	read__file(f);
	fclose(f);
}


/**
 * read__file-reads a file
 * @fd: pointer-to-file descriptor
 * Return: void
 */

void read__file(FILE *fd)
{
	int line__number, format = 0;
	char *buf = NULL;
	size_t len = 0;

	for (line__number = 1; getline(&buf, &len, fd) != -1; line__number++)
	{
		format = parse__line(buf, line__number, format);
	}
	free(buf);
}


/**
 * parse__line-Separates-each-line-into-tokens-to determine
 * which function to call
 * @buffer: line-from-the file
 * @line_number: line-number
 * @format:  storage format.-If-0-Nodes-will-be-entered-as-a-stack.
 * if 1-nodes-will-be-entered-as-a-queue.
 * Return: Returns-0-if-the-opcode is stack. 1 if queue.
 */

int parse__line(char *buffer, int line_number, int format)
{
	char *opcd, *val;
	const char *delimeter = "\n ";

	if (buffer == NULL)
		err(4);

	opcd = strtok(buffer, delimeter);
	if (opcd == NULL)
		return (format);
	val = strtok(NULL, delimeter);

	if (strcmp(opcd, "stack") == 0)
		return (0);
	if (strcmp(opcd, "queue") == 0)
		return (1);

	find__func(opcd, val, line_number, format);
	return (format);
}

/**
 * find__func -find the-appropriate-function-for-the opcode
 * @opcode: opcode-
 * @value: argument-of-opcode
 * @format:  storage-format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find__func(char *opcode, char *value, int ln, int format)
{
	int x;
	int fg;

	instruction_t func__list[] = {
		{"push", add__to__stack},
		{"pall", print__stack},
		{"pint", print__top},
		{"pop", pop__top},
		{"nop", nop},
		{"swap", swap__nodes},
		{"add", add__nodes},
		{"sub", sub__nodes},
		{"div", div__nodes},
		{"mul", mul__nodes},
		{"mod", mod__nodes},
		{"pchar", print__char},
		{"pstr", print__str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (fg = 1, x = 0; func__list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, func__list[x].opcode) == 0)
		{
			call__fun(func__list[x].f, opcode, value, ln, format);
			fg = 0;
		}
	}
	if (fg == 1)
		err(3, ln, opcode);
}


/**
 * call__fun - Calls the required function.
 * @func: Pointer-to-the-function-that-is-about-to-be called.
 * @op: string-representing-the-opcode.
 * @val: string-representing-a-numeric-value.
 * @ln: line numeber-for-the-instruction.
 * @format: Format specifier.-If-0-Nodes-will-be-entered as a stack.
 * if 1-nodes will-be entered as a queue.
 */
void call__fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *nd;
	int fg;
	int x;

	fg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			fg = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
				err(5, ln);
		}
		nd = create__node(atoi(val) * fg);
		if (format == 0)
			func(&nd, ln);
		if (format == 1)
			add__to__queue(&nd, ln);
	}
	else
		func(&head, ln);
}
