#include "shell.h"

/**
 * read_from_file - opens a file when reading cmds from file
 * @argc: number of args given when running the program
 * @argv: vector of args
 * Return: stream
 */

FILE *read_from_file(int argc, char *argv[])
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
			/*return (EXIT_FAILURE);*/
		}
	}
	return (fp);
}
