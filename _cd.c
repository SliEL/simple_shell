#include "shell.h"

/**
 * change_directory_path - Helper function to change
 * directory to the specified path
 * @dir: The directory path to change to
 * Return: true if the directory was changed successfully,
 * false otherwise
 */
bool change_directory_path(char *dir)
{
	if (chdir(dir) != 0)
	{
		/*perror("chdir");*/
		return (false);
	}

	return (true);
}

/**
 * change_directory_home - change to home
 * Return: true if the directory was changed successfully,
 * false otherwise
 */
bool change_directory_home(void)
{
	char *home_dir = _getenv("HOME");

	if (home_dir == NULL)
	{
		perror("Home directory not set\n");
		return (false);
	}

	return (change_directory_path(home_dir));
}

/**
 * change_directory_previous - change to previous dir
 *
 * Return:  true if the directory was changed successfully,
 * false otherwise cd -
 */
bool change_directory_previous(void)
{
	char *previous_dir = _getenv("OLDPWD");

	if (previous_dir == NULL)
	{
		perror("No previous directory available\n");
		return (false);
	}
	_puts(previous_dir);
	_puts("\n");
	return (change_directory_path(previous_dir));
}

/**
 * change_directory - _cd function
 * @dir: dir to change to
 * Return: true if the directory was changed successfully
 * check if cmd == "cd" ==> exit
 * false otherwise
 */

bool change_directory(char *dir)
{
	char current_dir[PATH_MAX];

	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		perror("getcwd");
		return (false);
	}
	if (dir != NULL && _strcmp(dir, "-") == 0)
	{
		return (change_directory_previous());
	}
	else if (dir == NULL)
	{
		return (change_directory_home());
	}
	else
	{
		return (change_directory_path(dir));
	}
}
