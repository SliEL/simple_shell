#include "shell.h"
#define BUFFER_SIZE 1024
/**
 * main - Entry point of the shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	char **env = environ;
	char *command = NULL, *BIN_PATH = "/bin/", *cmd;
	int check, status, i = 0, g = 0, len_cmd, k, e;
	size_t n = 0;
	char *args[BUFFER_SIZE], *argss[BUFFER_SIZE];
	while (1)
	{

		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "($)", 3);
		g = _getline(&command, n, STDIN_FILENO);
		if (g == -1)
		{
			free(command);
			perror("getline error");
			exit(-1);
		}
		if (g == 0)
		{
			free(command);
			return (-1);
		}
		if (command[0] == '\n')
		{
			free(command);
			continue;
		}
		remove_comment(command);
		len_cmd = _strlen(command);

		if (command[len_cmd - 1] == '\n')
			command[len_cmd - 1] = '\0';
		clean_command(command);
		k = and_check(command);
		next_line_handle(command, argss);
		i = 0;
		e = 0;
		while (argss[i])
		{
			args_array(argss[i], args);
			if (_strcmp(args[0], "cd") == 0)
			{
				if (change_directory(args[1]) == false)
					dir_not_found_message(argc, argv[0], args[1]);
				i++;
				continue;
			}

			status = exit_chek(args);
			if (_strcmp(argss[i], "exit") == 0)
			{
				if (i > 0)
				{
					free(command);
					exit(2);
				}
				if (args[1] == NULL)
					exit(status);
				if (!check_if_integer(args[1]))
				{
					exit_status_error_message(argc, argv[0], args[1]);
					free(command);
					exit(2);
				}
				if (status < 0)
				{
					free(command);
					exit_error_message(argc, argv[0], status);
					exit(2);
				}
				if (status == 0)
				{
					if (_strcmp(argss[0], "exit") != 0)
					{

						free(command);
						exit(2);
					}
					else
					{
						free(command);
						exit(status);
					}
				}

				if (status < 1500)
				{
					free(command);
					exit(status);
				}
			}
			check = command_cheker(command, BIN_PATH);
			cmd = get_command_name(args[0], BIN_PATH);

			if (k > 0)
			{
				if (command_exist(cmd, BIN_PATH) != 0)
				{
					not_found_message(argc, argv[0], cmd);
					if (isatty(STDIN_FILENO) == 0)
					{
						free(cmd);
						exit(127);
					}
					break;
				}
			}

			if (command_exist(cmd, BIN_PATH) != 0)
			{
				not_found_message(argc, argv[0], cmd);
				if (isatty(STDIN_FILENO) == 0)
				{
					free(cmd);
					exit(127);
					break;
				}
			}
			else
				execute_command(args, env);

			if (check == 0)
				free(cmd);

			i++;
		}
		free(command);
		if (isatty(STDIN_FILENO) == 0)
		{
			if (k > 0 && e > 0)
				exit(2);
			else
				exit(0);
		}
	}

	return (0);
}
