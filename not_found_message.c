#include "shell.h"
/**
 * not_found_message - Prints a "not found" error message.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @command: The command that was not found.
 */
void not_found_message(int argc, char *argv, char *command)
{
	char arg_count = '0' + argc;
	char *not_found_message = ": not found\n";

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, &arg_count, 1);
	write(2, ": ", 2);

	write(2, command, _strlen(command));

	write(2, not_found_message, _strlen(not_found_message));
}
/**
 * dir_not_found_message - Prints a "not found" error message.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @args_one: The command that was not found.
 */
void dir_not_found_message(int argc, char *argv, char *args_one)
{
	char arg_count = '0' + argc;
	char *not_found_message = ": cd: can't cd to ";

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, &arg_count, 1);

	write(2, not_found_message, _strlen(not_found_message));
	write(2, args_one, _strlen(args_one));
	write(2, "\n", 1);
}
/**
 * exit_error_message - Prints an error message for an illegal exit status.
 * @argc: The argument count.
 * @argv: The argument vector.
 * @args_one: The first argument.
 */
void exit_error_message(int argc, char *argv, int args_one)
{
	char arg_count = '0' + argc;
	char *not_found_message;
	char e, b;

	args_one = -args_one;
	e = (args_one / 10) + '0';
	b = (args_one % 10) + '0';
	not_found_message = ": exit: Illegal number: ";

	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, &arg_count, 1);

	write(2, not_found_message, _strlen(not_found_message));
	write(2, "-", 1);
	write(2, &e, 1);
	write(2, &b, 1);
	write(2, "\n", 1);
}
/**
 * exit_status_error_message - Prints an error message
 * for an illegal exit status.
 * @argc: The argument count.
 * @argv: The argument vector.
 * @args_one: The first argument.
 */
void exit_status_error_message(int argc, char *argv, char *args_one)
{
	char arg_count = '0' + argc;
	char *not_found_message;

	not_found_message = ": exit: Illegal number: ";
	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, &arg_count, 1);

	write(2, not_found_message, _strlen(not_found_message));
	write(2, args_one, _strlen(args_one));
	write(2, "\n", 1);
}
