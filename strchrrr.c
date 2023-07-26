#include "shell.h"

/**
 * _strchrrr - search for first occur of char in str
 * @str: ptr to the string
 * @target: target char
 * Return: ptr to first occur of the char in str
 */

char *_strchrrr(const char *str, int target)
{
	while (*str != '\0')
	{
		if (*str == target)
			return ((char *)str);
		str++;
	}
	if (target == '\0')
		return ((char *)str);
	return (NULL);
}
