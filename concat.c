#include "shell.h"
/**
 * concat - concatenates two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to destination string
 */
char *concat(char *dest, char *src)
{
	int i, j;
	int len_s = strlen(src);
	int len_d = strlen(dest);
	int len_final = len_s + len_d;

	for (i = len_d, j = 0; i <= len_final; i++, j++)
	{
		dest[i] = src[j];
	}
	dest[len_final] = '\0';
	return (dest);
}
