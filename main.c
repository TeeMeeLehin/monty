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
char *line = NULL;
size_t line_len = 0;
char *tokens[5];
unsigned int line_number;
stack_t *stack = NULL;
void (*f)(stack_t **stack, unsigned int line_number);

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

line_number = 1;
while (getline(&line, &line_len, file) != -1)
{
tokenizer(line, tokens);
data = tokens[1];
f = get_opcode(tokens[0]);
if (!f)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
exit(EXIT_FAILURE);
}
f(&stack, line_number);
line_number++;
}
free(line);
fclose(file);
return (0);
}
