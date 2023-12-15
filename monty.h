#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack__t *head;
typedef void (*op_func)(stack__t **, unsigned int);

/*file_operations*/
void open__file(char *file__name);
int parse__line(char *buffer, int line__number, int format);
void read__file(FILE *);
int len__chars(FILE *);
void find__func(char *, char *, int, int);

/*Stack_operations*/
stack_t *create__node(int n);
void free__nodes(void);
void print__stack(stack_t **, unsigned int);
void add__to__stack(stack_t **, unsigned int);
void add__to__queue(stack_t **, unsigned int);

void call__fun(op_func, char *, char *, int, int);

void print__top(stack_t **, unsigned int);
void pop__top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap__nodes(stack_t **, unsigned int);

/*Math_operations_with nodes*/
void add__nodes(stack_t **, unsigned int);
void sub__nodes(stack_t **, unsigned int);
void div__nodes(stack_t **, unsigned int);
void mul__nodes(stack_t **, unsigned int);
void mod__nodes(stack_t **, unsigned int);

/*String_operations*/
void print__char(stack_t **, unsigned int);
void print__str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error_hanlding*/
void err(int error_code, ...);
void more__err(int error_code, ...);
void string__err(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif