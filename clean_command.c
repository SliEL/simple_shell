#include "shell.h"

/**
 * _isspace - checks if char is space or not
 * @c: integer c
 * Return: int
 */

int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\r' || c == '\v' || c == '\f');
}
/**
 * clean_command - clean the command
 * @command: the string to clean
 */
void clean_command(char *command)
{
	{

		int length = _strlen(command);
		int i = length - 1;

		while (i >= 0 && _isspace(command[i]))
		{
			command[i] = '\0';
			i--;
		}
	}
}
