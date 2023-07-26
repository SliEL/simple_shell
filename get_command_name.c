#include "shell.h"
/**
 * command_cheker - Checks if a command
 *  is located in the specified binary path.
 * @command: The command to check.
 * @BIN_PATH: The binary path to compare against.
 *
 * Return: 0 if the command is in the binary path, -1 otherwise.
 */
int command_cheker(char *command, char *BIN_PATH)
{
	int len_bin = _strlen(BIN_PATH);

	if (_strncmp(command, BIN_PATH, len_bin - 1) == 0)
		return (0);
	else
		return (-1);
}
/**
 * get_command_name - Extracts the command name from a full command path.
 * @command: The full command path.
 * @BIN_PATH: The path to the binary directory.
 *
 * Return: The extracted command name.
 */
char *get_command_name(char *command, char *BIN_PATH)
{
	int len_bin = _strlen(BIN_PATH);
	char *cmd;

	if (_strncmp(command, BIN_PATH, len_bin - 1) == 0)
	{
		cmd = _strrchr(command, '/');
	}
	else
	{
		cmd = command;
	}
	return (cmd);
}
