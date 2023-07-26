#include "shell.h"
/**
 * _strncmp - compares two strings
 *
 * @s1: first string to be compared
 * @s2: second string to be compared
 * @n : number of characteres to compare
 * Return: 0 if s1 and s2 are equal and -1 if they are not
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}
