#include "shell.h"
/**
 * check_if_integer - Checks if a string contains only numbers.
 * @str: The string to check.
 *
 * Return: true if the string contains only numbers, false otherwise.
 */

bool check_if_integer(char *str)
{
	int i = 0;

	if (str == NULL || str[0] == '\0')
	{
		return (false);
	}

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (false);
		}
		i++;
	}

	return (true);
}

/**
 * exit_chek - Checks if the command is an exit command and handles it.
 * @args: The array of command arguments.
 *
 * Return: 0 on success, -100 on error.
 */
int exit_chek(char **args)
{
	int count = 0;

	while (args[count] != NULL)
		count++;
	if (_strcmp(args[0], "exit") == 0)
	{
		if (count == 1)
			return (0);
		if (count == 2)
		{
			return (_atoi(args[1]));
		}
	}

	return (1500);
}
