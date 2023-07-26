#include "shell.h"
#define BUFFER_SIZE 1024

/**
 * next_line_handle - Tokenizes a command
 *  into arguments using delimiters "&;\n".
 * @command: The command to tokenize.
 * @args: An array to store the tokenized arguments.
 *
 * Return: The number of arguments.
 */
int next_line_handle(char *command, char **args)
{
	char *token;
	int i = 0;

	token = strtok(command, "&;\n");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, "&;\n");
	}
	args[i] = NULL;
	return (i);
}

/**
 * and_check - Counts the number of occurrences of "&&" in a command.
 * @command: The command to check.
 *
 * Return: The count of "&&" occurrences.
 */
int and_check(char *command)
{
	int i = 0, count = 0;

	while (command[i])
	{
		if (command[i] == '&' && command[i + 1] == '&')
			count++;
		i++;
	}
	return (count);
}
