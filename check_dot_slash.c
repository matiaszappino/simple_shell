#include "shell.h"
/**
 *check_dot_slash - ckecks in command for dot ands slash only
 *@args: arguments vector
 *@count: history counter
 *@av: name of program
 *@buffer: buffer
 *Return: 1 if success, 0 if not
 */

int check_dot_slash(char **args, int count, char *av, char *buffer)
{
	if (*args[0] == '.' && _strlen(args[0]) == 1)
	{
		print_error(args[0], count, "filename argument required", av);
		free(args);
		free(buffer);
		return (1);
	}
	if (*args[0] == '/' && _strlen(args[0]) == 1)
	{
		print_error(args[0], count, "Is a directory", av);
		free(args);
		free(buffer);
		return (1);
	}
	return (0);
}
