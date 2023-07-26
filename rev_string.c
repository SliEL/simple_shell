#include "shell.h"
/**
 * rev_string - reverses a string
 * @s: the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	int len = strlen(s);
	char temp;
	int i, j;

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
