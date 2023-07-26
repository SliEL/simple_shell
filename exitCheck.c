#include "shell.h"
#include <ctype.h>
/**
 * checkNumber - Checks if a string represents a valid number.
 * @string: The input string to check.
 *
 * Return: 1 if the string represents a valid number, 0 otherwise.
 */
int checkNumber(char *string)
{
	int i;

	if (string == NULL)
		return (0);
	for (i = 0; string[i] != '\0'; i++)
	{
		if (!isdigit(string[i]))
		{
			return (0);
		}
	}

	return (1);
}
/**
 * exitCheck - Checks if the "exit" command is provided
 * and exits the shell if necessary.
 * @args: An array of arguments, where args[0] is the command
 * and args[1] onwards are arguments.
 * @buffer: The input buffer that stores the command line.
 */

void exitCheck(char **args, char *buffer)
{
	int status = 0;

	if ((_strcmp(args[0], "exit") == 0) && (checkNumber(args[1]) == 1))
	{
		status = atoi(args[1]);
		free(args);
		free(buffer);
		exit(status);
	}
	if (strcmp(args[0], "exit") == 0)
	{
		free(buffer);
		free(args);
		exit(EXIT_SUCCESS);
	}
}
