#include "shell.h"
/**
 * main - Main function to run the shell.
 * @argc: The argument count.
 * @argv: The argument vector.
 * Return: The exit status of the shell.
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL, *fullPath, **args, **env = environ;
	size_t bufsize = 0;
	FILE *fp = stdin; /* file pointer defaults to stdin */

	/*If a file argument was provided, attempt to open the file*/
	if (argc > 1)
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argv[0]);
				_eputs(": 0: Can't open ");
				_eputs(argv[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
	}

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
		execute_command(args, env);
		free(args);
		free(fullPath);
		args = NULL;
	}
	if (fp != stdin)
	{
		fclose(fp);
	}
	free(buffer);
	return (EXIT_SUCCESS);
}
