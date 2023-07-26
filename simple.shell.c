#include "shell.h"

int last_status = 0;
/**
 * main - Main function to run the shell.
 * @argc: The argument count.
 * @argv: The argument vector.
 * Return: The exit status of the shell.
 */

int main(int argc, char *argv[])
{
	FILE *fp = stdin;

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
	hsh(argc, argv, fp);
	if (fp != stdin)
	{
		fclose(fp);
	}
	return (last_status);
}
