#include "shell.h"
/**
 * _puts - Prints a string to stdout.
 * @s: The string to print.
 *
 * Return: Always 0.
 */
int _puts(const char *s)
{
	while (*s)
	{
		_putchar(*s);
		s++;
	}
	return (0);
}
