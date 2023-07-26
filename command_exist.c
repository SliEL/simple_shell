#include "shell.h"

/**
 * command_exist - Checks if a command exists in a given directory.
 * @command: The command to check.
 * @path: The directory to search in.
 *
 * Return: 0 if the command exists, -1 otherwise.
 */
int command_exist(char *command, char *path)
{
	DIR *dir = opendir(path);
	struct dirent *entry;

	if (dir == NULL)
	{
		perror("Unable to open directory");
		return (-1);
	}

	while ((entry = readdir(dir)) != NULL)
	{
		if (_strcmp(entry->d_name, command) == 0)
		{
			closedir(dir);
			return (0);
		}
	}

	closedir(dir);
	return (-1);
}
