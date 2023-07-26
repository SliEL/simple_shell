#include "shell.h"
/**
 * handlePath - Prepends "/bin/" to the command if not already present.
 * @command: The command to check and modify.
 * Return: The modified command with the full path.
 */
char *handlePath(char *command)
{
	char *fullPath;

	if (strncmp(command, "/bin/", 5) != 0)
	{
		fullPath = malloc(sizeof(char) * (_strlen(command) + 6));
		_strcpy(fullPath, "/bin/");
		_strcat(fullPath, command);
		return (fullPath);
	}
	fullPath = malloc(sizeof(char) * (_strlen(command) + 1));
	_strcpy(fullPath, command);
	return (fullPath);
}
