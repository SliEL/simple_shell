#include "shell.h"
/**
 * _strtok - Tokenize a string by splitting it into
 *           substrings based on a delimiter.
 * @str: The input string to be tokenized.
 * @delim: The delimiter character used to split the string.
 *
 * Return: A pointer to the next token found in the string
 *         or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *save_ptr;
	char *token_start;
	char *token_end;

	if (str != NULL)
		save_ptr = str;

	if (save_ptr == NULL || *save_ptr == '\0')
		return (NULL);

	while (_strchr(delim, *save_ptr) != NULL)
		save_ptr++;

	token_start = save_ptr;
	token_end = _strchr(token_start, *delim);

	if (token_end != NULL)
	{
		*token_end = '\0';
		save_ptr = token_end + 1;
	}
	else
	{
		save_ptr = NULL;
	}

	return (token_start);
}
