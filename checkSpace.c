#include "shell.h"

/**
 * check_spaces - Checks if the buffer contains only spaces.
 * @buffer: The input buffer to be checked.
 *
 * Return: -1 if the buffer contains non-space characters,
 *         1 if the buffer contains only spaces.
 */
int check_spaces(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		if (buffer[i] != ' ')
		{
			return (-1);
		}
		i++;
	}

	return (1);
}
