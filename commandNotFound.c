#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * reverseString - Reverses a string in-place.
 * @str: The input string to be reversed
 */
void reverseString(char *str)
{
	int length = 0;
	char *end = str;

	while (*end != '\0')
	{
		length++;
		end++;
	}

	end--;

	while (str < end)
	{
		char temp = *str;
		*str = *end;
		*end = temp;

		str++;
		end--;
	}
}
/**
 * intToString - Converts an integer to a string.
 * @number: The integer to be converted.
 * @result: The output string where the converted number will be stored.
 */
void intToString(int number, char *result)
{
	int i = 0;
	int isNegative = 0;

	if (number < 0)
	{
		isNegative = 1;
		number = -number;
	}

	while (number > 0)
	{
		result[i++] = (number % 10) + '0';
		number /= 10;
	}

	if (isNegative)
		result[i++] = '-';

	result[i] = '\0';

	reverseString(result);
}
/**
 * notFoundMessage - Prints a "not found" error message to stderr.
 * @a: The numeric identifier.
 * @executable: The name of the executable (e.g., the shell name).
 * @token: The command or token that was not found.
 */

void notFoundMessage(int a, char *executable, char *token)
{
	char str[1];

	intToString(a, str);
	write(STDERR_FILENO, executable, _strlen(executable));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, token, _strlen(token));
	write(STDERR_FILENO, ": not found\n", 12);
}
/**
 * commandNotFound - Checks if a command is not found in the system.
 * @command: The name of the command to check.
 *
 * Return: 1 if the command is found, -1 if it is not found.
 */
int commandNotFound(char *command)
{
	if (access(command, F_OK) != -1)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}
