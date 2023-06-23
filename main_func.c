#include "monty.h"

/**
* push - function to add to a stack
* @tokens: tokenized inputs
* @line_no: line number of instruction
* @rack: existing stack
* Return: void
*/
void push(char **tokens, unsigned int line_no, stack_t **rack)
{
stack_t *new_rack = malloc(sizeof(stack_t));
int element = atoi(tokens[1]);

if (!new_rack)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

if (!tokens[1] || tokens[1][0] == '\0')
{
fprintf(stderr, "L%d: usage: push integer\n", line_no);
free(new_rack);
exit(EXIT_FAILURE);
}


new_rack->n = element;
new_rack->prev = NULL;
new_rack->next = *rack;

if (*rack)
{
(*rack)->prev = new_rack;
}

*rack = new_rack;
}

/**
* pall - printing all elements in a stack
* @rack: the input stack
* Return: void
*/
void pall(stack_t *rack)
{
stack_t *temp = rack;
while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}

/**
* pint - printing the stack's top element
* @rack: the input stack
* Return: void
*/
void pint(stack_t *rack)
{
stack_t *temp = rack;
printf("%d\n", temp->n);
}

/**
* pop - popping the stack
* @line_no: line number of instruction
* @rack: the input stack
* Return: void
*/
void pop(stack_t **rack, unsigned int line_no)
{
stack_t *temp = *rack;
if (!temp)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
exit(EXIT_FAILURE);
}
if (temp->next == NULL)
{
free(temp);
*rack = NULL;
}
else
{
*rack = (*rack)->next;
(*rack)->prev = NULL;
free(temp);
}
}

/**
* swap - swapping the top two elements of the stack
* @line_no: line number of instruction
* @rack: the input stack
* Return: void
*/
void swap(stack_t **rack, unsigned int line_no)
{
stack_t *temp = *rack;
int n;
if (*rack == NULL || (*rack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short", line_no);
exit(EXIT_FAILURE);
}
n = temp->n;
temp->n = temp->next->n;
temp->next->n = n;
}

/**
* void - does nothing
* Return: void
*/
void nop(void)
{
return;
}

/**
* add - adding the top two elements of the stack
* @line_no: line number of instruction
* @rack: the input stack
* Return: void
*/
void add(stack_t **rack, unsigned int line_no)
{
stack_t *temp = *rack;
int n;
if (*rack == NULL || (*rack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short", line_no);
exit(EXIT_FAILURE);
}
n = temp->n;
temp->n = temp->next->n;
temp->next->n = temp->next->n + n;
pop(rack, line_no);
}