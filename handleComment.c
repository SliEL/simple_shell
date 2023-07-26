#include "shell.h"
/**
 * this_is_comment - Chek if there is a comment
 * @line: the input line to precess.
 * Return: 1 if yes -1 if not
 */
int this_is_comment(char *line)
{

	int i = 0;

	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] == '#')
			return (1);
		i++;
	}
	return (-1);
}
/**
 * handleComment - Removes any comments from the input line.
 * @line: The input line to process.
 */
void handleComment(char *line)
{
	char *comment_ptr;
	int len;

	if (this_is_comment(line) == 1)
	{
		comment_ptr = _strchr(line, '#');

		if (comment_ptr)
			*comment_ptr = '\0';

		len = _strlen(line);
		while (len > 0 && _isspace(line[len - 1]))
		{
			line[len - 1] = '\0';
			len--;
		}
	}
}
