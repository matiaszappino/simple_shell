#include "shell.h"
/**
 * check_path - check if args[0] is a valid path
 * @args: argument vector
 * Return: 0 if success, 1 if not
 **/
int check_path(char **args)
{
	struct stat fileStat;

	if (stat(args[0], &fileStat) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
