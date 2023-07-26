#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <stdbool.h>

#define PATH_MAX 4096

extern char **environ;

/* change directory */
bool change_directory(char *dir);
bool change_directory_previous(void);
bool change_directory_home(void);
bool change_directory_path(char *dir);
char *_getenv(char *name);

int _strncmp(char *s1, char *s2, int n);
char *copy(char *dest, char *src);
char *concat(char *dest, char *src);
int command_exist(char *command, char *path);
int _strlen(char *str);
void rev_string(char *s);
char *_strrchr(char *s, char c);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
int _puts(const char *s);
int args_array(char *command, char **args);
int execute_command(char **args, char **env);
void read_command(char **command, size_t *n);
char *get_command_name(char *command, char *BIN_PATH);
ssize_t _getline(char **line, size_t n, int fileDescriptor);
char *_strtok(char *str, char *del);
int _atoi(char *s);
int exit_chek(char **args);
int commands_separator(char *command, char **args);
char *delete_spaces(char *str, const char c);
void execute_with_separator(char **args, char **env, char **separato_args);
char *find_path(char *command);
int and_handle(char *command, char **args);
void clean_command(char *command);
int next_line_handle(char *command, char **args);
void not_found_message(int argc, char *argv, char *command);
int command_cheker(char *command, char *BIN_PATH);
void remove_comment(char *lineptr);
char *_strchrrr(const char *str, int target);
int and_check(char *command);
void dir_not_found_message(int argc, char *argv, char *args_one);
char *_getcwd(char *buf, size_t size);
void exit_error_message(int argc, char *argv, int args_one);
void exit_status_error_message(int argc, char *argv, char *args_one);
bool check_if_integer(char *str);

#endif
