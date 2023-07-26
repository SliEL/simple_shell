#include "shell.h"
/**
 * _strcmp - compares two strings
 *
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: 0 if s1 and s2 are equal, < 0 if s1 < s2, > 0 if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
