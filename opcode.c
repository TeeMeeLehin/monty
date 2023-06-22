#include "monty.h"

/**
* get_opcode - Get the opcode's corresponding function
* @str: The opcode to get a function for
* Return: A pointer to the corresponding function
*/

void (*get_opcode(char *str))(stack_t **stack, unsigned int line_number)
{
int i = 0;
instruction_t opcodes[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{"pop", pop},
};

while (i < 4)
{
if (strcmp(opcodes[i].opcode, str) == 0)
{
return (opcodes[i].f);
}
i++;
}

return (NULL);
}
