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
