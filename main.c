#include "monty.h"
all_t ALL = {NULL, NULL, NULL, 1};

/**
 * main - Entry point of the interpreter.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 *
 * This function opens the file containing the Monty byte codes and interprets
 * them. If the file cannot be opened or read, or if the wrong number of
 * arguments is given, the function will print an error message to stderr and
 * exit with a status of EXIT_FAILURE.
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t reads = 1;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

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

	ALL.file = file;

	while (reads > 0)
	{
		line = NULL;
		reads = getline(&line, &len, file);
		line_num++;
		ALL.line = line;

		if (reads > 0)
			cmd_handler(line, &stack, line_num, file);

		free(line);
	}

	fclose(file);
	free_list(stack);
	return (EXIT_SUCCESS);
}

/**
 * cmd_handler - Handles the commands read from the Monty byte code file.
 * @line: The line from the file.
 * @stack: A double pointer to the beginning of the stack.
 * @line_num: The line number where the instruction was found.
 * @file: The Monty byte code file.
 *
 * This function tokenizes the line into an opcode and an optional argument.
 * It then executes the opcode if it is a recognized command. If the opcode
 * is not recognized, the function will print an error message to stderr and
 * exit with a status of EXIT_FAILURE.
 *
 * Return: 0 on success, 1 on failure.
 */

int cmd_handler(char *line, stack_t **stack, unsigned int line_num, FILE *file)
{
	instruction_t op_table[] = {
		{"push", mypush}, {"pall", mypall}, {"pint", mypint}, {"pop", mypop},
		{"swap", myswap}, {"add", myadd}, {"nop", mynop},
		{"sub", mysub}, {"div", mydiv}, {"mul", mymul}, {"mod", mymod},
		{"pchar", mypchar}, {"pstr", mypstr}, {"rotl", myrotl}, {"rotr", myrotr},
		{"stack", mystack}, {"queue", myqueue}, {NULL, NULL}};
	char *opcode = NULL;
	unsigned int i = 0;

	opcode = strtok(line, " \n\t\a\b");

	if (opcode && opcode[0] == '#')
		return (0);

	ALL.arg = strtok(NULL, " \n\t\a\b");
	for (i = 0; op_table[i].opcode && opcode; i++)
	{
		if (strcmp(opcode, op_table[i].opcode) == 0)
		{
			op_table[i].f(stack, line_num);
			return (EXIT_SUCCESS);
		}
	}

	if (opcode && op_table[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, opcode);
		fclose(file);
		free(line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
