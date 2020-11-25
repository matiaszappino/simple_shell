#include "shell.h"
/**
 *check_dot_slash - ckecks in command for dot ands slash only
 *@args: arguments vector
 *@count: history counter
 *@path: path of command
 *@av: name of program
 *@buffer: buffer
 */

void check_dot_slash(char **args, int count, char *path,
char *av, char *buffer)
{
	if (*args[0] == '.' && _strlen(args[0]) == 1)
	{
		print_error(args[0], count, "filename argument required", av);
		free_memory(args, path, buffer);
		exit(126);
	}
	if (*args[0] == '/' && _strlen(args[0]) == 1)
	{
		print_error(args[0], count, "Is a directory", av);
		free_memory(args, path, buffer);
		exit(2);
	}
}
