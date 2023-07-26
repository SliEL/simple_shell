#ifndef SHELL_H
#define SHELL_H
#define PATH_MAX 4096
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <limits.h>
#include <stdarg.h>
#include <errno.h>
extern char **environ;
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024

int hsh(int argc, char *argv[], FILE *fp);

void _eputs(char *str);
int _eputchar(char c);

int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strchr(const char *s, int c);
FILE *read_from_file(int argc, char *argv[]);
void free_stuff(char *p, char **ptr);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);

int _isspace(int c);
int check_spaces(char *buffer);
void printPrompt(void);
void *delete_spaces(char *prompt);
char **handleArguments(char *buffer);
int execute_command(char **args, char **env);
void exitCheck(char **args, char *buffer);
char *handlePath(char *command);
int commandNotFound(char *command);
void notFoundMessage(int a, char *executable, char *token);
int checkNumber(char *string);
char **handleSeparator(char *buffer);
void execute_separated_commands(char *commands, char **env);
void handleComment(char *command);
int this_is_comment(char *line);
void change_directory(char **args);
void execute_pwd(void);
#endif
