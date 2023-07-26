#include "shell.h"
/**
 * copy - copies characters of the source string
 * to the destination string, with null-termination.
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to the destination string
 */
char *copy(char *dest, char *src)
{
	int i;

	i = 0;
	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
