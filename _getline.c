#include "shell.h"
/**
 * _getline - Reads a line from a file descriptor.
 * @line: A pointer to the buffer storing the line.
 * @n: The maximum number of characters to read.
 * @fileDescriptor: The file descriptor to read from.
 *
 * Return: The number of characters read, -1 on failure.
 */
ssize_t _getline(char **line, size_t n, int fileDescriptor)
{
	char buf[10000];
	ssize_t r;

	if (n == 0)
	{
		r = read(fileDescriptor, buf, sizeof(buf));
	}
	else
		r = read(fileDescriptor, buf, n);
	if (r == -1)
	{
		return (-1);
	}
	if (r > 0)
	{
		buf[r] = '\0';
		*line = malloc((r + 1) * sizeof(char));
		if (*line == NULL)
			free(*line);
		copy(*line, buf);
	}
	return (r);
}
