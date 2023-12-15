#include "monty.h"

/**
 * open_file-opens-a-file
 * @file_name: the-file-namepath
 * Return: void
 */

void open__file(char *file__name)
{
	FILE *fd = fopen(file__name, "r");

	if (file__name == NULL || fd == NULL)
		err(2, file__name);

	read__file(fd);
	fclose(fd);
}


/**
 * read_file-reads a file
 * @fd: pointer-to-file descriptor
 * Return: void
 */

void read__file(FILE *fd)
{
	int line__number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line__number = 1; getline(&buffer, &len, fd) != -1; line__number++)
	{
		format = parse__line(buffer, line__number, format);
	}
	free(buffer);
}


/**
 * parse_line-Separates-each-line-into-tokens-to determine
 * which function to call
 * @buffer: line-from-the file
 * @line_number: line-number
 * @format:  storage format.-If-0-Nodes-will-be-entered-as-a-stack.
 * if 1-nodes-will-be-entered-as-a-queue.
 * Return: Returns-0-if-the-opcode is stack. 1 if queue.
 */

int parse__line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find__func(opcode, value, line_number, format);
	return (format);
}

/**
 * find_func -find the-appropriate-function-for-the opcode
 * @opcode: opcode-
 * @value: argument-of-opcode
 * @format:  storage-format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find__func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

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

	for (flag = 1, i = 0; func__list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func__list[i].opcode) == 0)
		{
			call__fun(func__list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer-to-the-function-that-is-about-to-be called.
 * @op: string-representing-the-opcode.
 * @val: string-representing-a-numeric-value.
 * @ln: line numeber-for-the-instruction.
 * @format: Format specifier.-If-0-Nodes-will-be-entered as a stack.
 * if 1-nodes will-be entered as a queue.
 */
void call__fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create__node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add__to__queue(&node, ln);
	}
	else
		func(&head, ln);
}