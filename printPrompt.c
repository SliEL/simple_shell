#include "shell.h"
/**
 * printPrompt - Prints the shell prompt.
 */
void printPrompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
