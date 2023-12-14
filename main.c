#include "monty.h"
/**
 * main - The monty program
 * @argc: arg count
 * @argv: arg vector
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	(void) argv;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
