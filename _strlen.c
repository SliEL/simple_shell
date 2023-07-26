#include "shell.h"
/**
 * _strlen - Returns the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int i = 0;

	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}
