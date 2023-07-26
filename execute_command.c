#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * execute_command - Executes a command with arguments.
 * @args: The array of command arguments.
 * @env: The environment variables.
 *
 * Return: Always 0.
 */
int execute_command(char **args, char **env)
{
	int len_arg, len_bin, status;
	pid_t pid;
	char *BIN_PATH = "/bin/";
	char *dest;
	int ncmp;

	len_bin = _strlen(BIN_PATH);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		ncmp = _strncmp(args[0], BIN_PATH, len_bin);
		if (ncmp == -1)
		{
			len_arg = strlen(args[0]);
			dest = malloc(sizeof(char) * (len_bin + len_arg + 1));
			if (dest == NULL)
				free(dest);
			copy(dest, BIN_PATH);
			concat(dest, args[0]);
			args[0] = dest;
		}
		execve(args[0], args, env);

		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
