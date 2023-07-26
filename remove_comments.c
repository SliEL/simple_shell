#include "shell.h"

/**
 * remove_comment - removes the comment part from the lineptr
 * @lineptr: the command line entered by the user
 * Return: void - nothing.
 * fjhfoeheo \0 fekhfeokj
 */

void remove_comment(char *lineptr)
{
	char *comment_pos;

	comment_pos = _strchrrr(lineptr, '#');
	if (comment_pos != NULL)
	{
		if (comment_pos == lineptr || *(comment_pos - 1) == ' ')
			*comment_pos = '\0';
	}
}
