#include "shell.h"

/**
 * free_stuff - free memory
 * @p: char ptr
 * @ptr: double ptr
 *
 * Return: Nothing
 */

void free_stuff(char *p, char **ptr)
{
	free(p);
	free(ptr);
}
