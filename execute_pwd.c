#include "shell.h"
/**
 * execute_pwd - Executes the "pwd" command.
 */
void execute_pwd(void)
{
	pid_t pid;
	char *pwd_args[] = {"/bin/pwd", NULL};
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(pwd_args[0], pwd_args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}
