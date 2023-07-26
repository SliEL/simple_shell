#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * args_array - Splits a command string into an array of arguments.
 * @command: The command string to split.
 * @args: An array to store the arguments.
 *
 * Return: The number of arguments.
 */
int args_array(char *command, char **args)
{
	char *token;
	int i = 0;

	token = strtok(command, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (i);
}
