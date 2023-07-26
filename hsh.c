#include "shell.h"

/**
 * hsh - main loop
 * @argc: number of args
 * @argv: vec args
 * @fp: stream to read from
 * Return: Nothing
 */
int hsh(int argc, char *argv[], FILE *fp)
{
	char *buffer = NULL, *fullPath, **args, **env = environ;
	size_t bufsize = 0;

	while (1)
	{
		printPrompt();
		if (_getline(&buffer, &bufsize, fp) == -1)
			break;
		if (_strcmp(buffer, "\n") == 0 || buffer[0] == '#')
			continue;
		delete_spaces(buffer);
		if (check_spaces(buffer) == 1)
			continue;
		handleComment(buffer);
		args = handleArguments(buffer);
		if (strcmp(args[0], "cd") == 0)
		{
			change_directory(args);
			free(args);
			continue;
		}
		exitCheck(args, buffer);
		fullPath = handlePath(buffer);
		args[0] = fullPath;
		if (commandNotFound(fullPath) == -1)
		{
			notFoundMessage(argc, argv[0], buffer);
			free(fullPath);
			free(args);
			if (!isatty(STDIN_FILENO))
				return (127);
			continue;
		}
		if (execute_command(args, env) == 512)
			last_status = 2;
		free_stuff(fullPath, args);
		args = NULL;
	}
	free(buffer);
	return (last_status);
}
