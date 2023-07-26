#include "shell.h"

/**
 * _getline - Read a line from a file stream.
 * @lineptr: A pointer to a char pointer to store the read line.
 * @n: A pointer to the size_t variable to store the allocated size
 *     of the buffer.
 * @stream: The file stream to read from (e.g., stdin).
 *
 * Return: The number of characters read (including the newline character),
 *         -1 on error or end-of-file (EOF).
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	size_t capacity = 0, index = 0;
	char *new_lineptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		capacity = 128;
		*lineptr = (char *)malloc(capacity);
		if (*lineptr == NULL)
			return (-1);

		*n = capacity;
	}
	while ((ch = fgetc(stream)) != EOF)
	{
		if (index >= *n - 1)
		{
			capacity *= 2;
			new_lineptr = (char *)realloc(*lineptr, capacity);
			if (new_lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = new_lineptr;
			*n = capacity;
		}
		(*lineptr)[index++] = ch;
		if (ch == '\n')
			break;
	}
	if (index == 0)
		return (-1);
	(*lineptr)[index] = '\0';
	return (index);
}
