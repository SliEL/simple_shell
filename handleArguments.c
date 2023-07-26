#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * handleArguments - Tokenizes the input buffer into arguments.
 * @buffer: The input buffer containing the command line.
 *
 * Return: An array of strings representing the command and its arguments.
 */
char **handleArguments(char *buffer)
{
	char **args = malloc(sizeof(char) * BUFFER_SIZE);
	char *token;
	int i = 0;

	token = _strtok(buffer, " ");

	while (token)
	{
		args[i] = token;
		token = _strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;

	return (args);
}
