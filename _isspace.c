#include "shell.h"
/**
 * _isspace - Checks if a character is a whitespace character.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is a whitespace, 0 otherwise.
 */

int _isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\r' || c == '\v' || c == '\f');
}
/**
 * delete_spaces - Trims leading and trailing spaces from a string.
 * @prompt: The input string to be modified.
 *
 * Return: A pointer to the modified string.
 */
void *delete_spaces(char *prompt)
{

	int start = 0, i = 0;
	int end;

	end = _strlen(prompt) - 1;
	while (_isspace(prompt[start]))
		start++;
	while (end > start && _isspace(prompt[end]))
		end--;
	for (i = 0; i <= end - start; i++)
		prompt[i] = prompt[start + i];
	prompt[i] = '\0';
	return (0);
}
