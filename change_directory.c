#include "shell.h"
/**
 * change_directory - Changes the current working directory.
 * @args: An array of arguments, where args[0]
 *  is the command and args[1] is the directory.
 */
void change_directory(char **args)
{
	char *home_dir, *previous_dir = NULL, current_dir[1024];

	if (args[1] == NULL)
	{
		home_dir = getenv("HOME");
		if (home_dir)
			chdir(home_dir);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		previous_dir = getenv("OLDPWD");
		if (previous_dir)
		{
			chdir(previous_dir);
			execute_pwd();
		}
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("cd");
	}
	if (getcwd(current_dir, sizeof(current_dir)) != NULL)
		setenv("PWD", current_dir, 1);
	else
		perror("getcwd");
}
