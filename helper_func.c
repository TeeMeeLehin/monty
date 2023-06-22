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
* run_opcode - function that switches and run opcodes
* @tokens: input tokens
* @rack: current stack
* @line_no: line number of instruction
* Return: void

void run_opcode(char **tokens, stack_t *rack, unsigned int line_no)
{
if (strcmp(tokens[0], "push") == 0)
{
push(tokens, line_no, &rack);
}
else if (strncmp(tokens[0], "pall", 4) == 0)
{
pall(rack);
}
else if (strcmp(tokens[0], "pint") == 0)
{
pint(rack);
}
else if (strcmp(tokens[0], "pop") == 0)
{
pop(&rack, line_no);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_no, tokens[0]);
exit(EXIT_FAILURE);
}
}
*/
