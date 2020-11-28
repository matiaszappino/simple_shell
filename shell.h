#ifndef _SHELL_H_
#define _SHELL_H_
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>
#define BUFFSIZE 1024

extern char **environ;
int loop(char *av);
void prompt(void);
char *save_buffer(void);
char *checkspaces(char *buffer);
int _atoi(char *s);
char **split_buffer(char *pbuffer, int *num, int count, char *av);
int execute(char **args, char *av, char **env_var,
char *path, char *buffer, int check);
char *find_path(char **environ, char **args);
char *split_path(char *path, char **args);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int len);
int _putchar(char c);
void print_number(int n);
int search_builtin(char *token, char **tokens, char *buffer,
char *av, int count);
int builtin_exit(char *token, char **tokens, char *buffer,
char *av, int count);
int builtin_env(char *token, char **tokens);
int check_dot_slash(char **args, int count, char *av, char *buffer);
void print_error(char *argv, int count, char *error_name, char *name);
void print_error2(char *argv, int count, char *error_name, char* num, char *name);
void free_memory(char **args, char *path, char *av);
void kill_signal(int sig);
void _puts(char *str);
char **tokenize(char *token, char **tokens, int *count);
int check_path(char **args);

/**
 *struct builtin - structure of builtins options
 *@reference: character option
 *@function: pointer to function
 */
typedef struct builtin
{
	char *reference;
	int (*function)();
} builtin;
#endif
