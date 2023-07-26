#include "shell.h"
/**
 * _strrchr - Locates the last occurrence of a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: Pointer to the last occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strrchr(char *s, char c)
{
	int len_s = strlen(s) - 1;
	char *b;
	int i = 0;

	b = malloc((len_s + 1) * sizeof(char));

	while (s[len_s] != c)
	{
		b[i] = s[len_s];
		len_s--;
		i++;
	}
	b[i] = '\0';
	rev_string(b);
	return (b);
}
