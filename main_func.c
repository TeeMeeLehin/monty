#include "monty.h"

/**
* push - function to add to a stack
* @line_number: line number of instruction
* @stack: existing stack
* Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_rack = malloc(sizeof(stack_t));
int element = atoi(data);

if (!new_rack)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

if (!data || data[0] == '\0')
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free(new_rack);
exit(EXIT_FAILURE);
}


new_rack->n = element;
new_rack->prev = NULL;
new_rack->next = *stack;

if (*stack)
{
(*stack)->prev = new_rack;
}

*stack = new_rack;

}

/**
* pall - printing all elements in a stack
* @stack: the input stack
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
(void)line_number;
}

/**
* pint - printing the stack's top element
* @stack: the input stack
* Return: void
*/
void pint(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;
printf("%d\n", temp->n);
(void)line_number;
}

/**
* pop - popping the stack
* @stack: the input stack
* @line_number: line number of instruction
* Return: void
*/
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;
if (!temp)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
if (temp->next == NULL)
{
free(temp);
*stack = NULL;
}
else
{
*stack = (*stack)->next;
(*stack)->prev = NULL;
free(temp);
}
}
