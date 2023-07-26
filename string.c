#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: input string
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}
	return (i);
}
/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if strings are equal, a negative value if s1 < s2,
 *         a positive value if s1 > s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;

	return (s1[i] - s2[i]);
}
/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string, where the result will be stored.
 * @src: The source string to be appended to dest.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int dest_len = 0;
	int i = 0;

	while (dest[dest_len] != '\0')
		dest_len++;

	while (src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}

	dest[dest_len] = '\0';
	return (dest);
}
/**
 * _strcpy - Copy a string.
 * @dest: The destination buffer, where the string will be copied to.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: A pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found.
 */
char *_strchr(const char *s, int c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);

	return (NULL);
}
