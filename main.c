#include "monty.h"

/**
* main - simple shell main function
* @argc: number of passed argumennts
* @argv: the array of passed arguments
* Return: int
*/
int main(int argc, char *argv[])
{
FILE *file;
char line[100], *tokens[5];
unsigned int line_no = 1;
stack_t *rack = NULL;
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while (fgets(line, 100, file) != NULL)
{
tokenizer(line, tokens);
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
else if (strcmp(tokens[0], "swap") == 0)
{
swap(&rack, line_no);
}
else if (strcmp(tokens[0], "nop") == 0)
{
nop();
}
else if (strcmp(tokens[0], "add") == 0)
{
add(&rack, line_no);
}
else
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_no, tokens[0]);
exit(EXIT_FAILURE);
}
line_no++;
}
fclose(file);
return (0);
}
