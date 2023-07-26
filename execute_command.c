#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * execute_command - Executes a command in a new process.
 * @args: An array of arguments, where args[0] is the command
 * and args[1] onwards are arguments.
 * @env: The environment variables.
 *
 * Return: Always returns 0.
 */
int execute_command(char **args, char **env)
{

	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{

		waitpid(pid, &status, 0);
	}
	return (status);
}
