#include "shell.h"

/**
 * _getenv - gets value of variable like getenv
 * @name: name of the variable
 * Return: NUll or ptr to value
 */

char *_getenv(char *name)
{
	char **env = environ;
	size_t nameLength;

	if (name == NULL || name[0] == '\0')
	{
		write(STDERR_FILENO, "Error: Invalid environment variable name.\n", 41);
		return (NULL);
	}

	nameLength = _strlen(name);

	for (; *env != NULL; env++)
	{
		if (_strncmp(*env, name, nameLength) == 0 && (*env)[nameLength] == '=')
		{
			return (&(*env)[nameLength + 1]);
		}
	}

	return (NULL);
}
