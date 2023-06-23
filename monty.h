#ifndef MAIN_H
#define MAIN_H

#define  _GNU_SOURCE
#define STACK_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void push(char **tokens, unsigned int line_no, stack_t **rack);
void pall(stack_t *rack);
void tokenizer(char *input, char *inputs[]);
void pint(stack_t *rack);
void pop(stack_t **rack, unsigned int line_no);
void swap(stack_t **rack, unsigned int line_no);
void nop(void);
void add(stack_t **rack, unsigned int line_no);

#endif
