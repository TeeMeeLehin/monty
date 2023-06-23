#include "monty.h"

/**
* tokenizer - function to tokenize inputs
* @input: input string
* @inputs: output array of tokens
* Return: void
*/
void tokenizer(char *input, char *inputs[])
{
int i = 0;
input = strtok(input, " \n");
while (input)
{
inputs[i] = input;
input = strtok(NULL, " \n");
i++;
}
inputs[i] = NULL;
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
* nop - does nothing
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
