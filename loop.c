/**
 * loop - loop.
 * @av: name of the program passed.
 * Return: 0 to EXIT_SUCCESS.
 */
#include "shell.h"
int loop(char *av)
{
	char *buffer = NULL, *strPath = NULL;
	char **args = NULL;
	int num_of_tokens = 0, check, status = 1, process = 0,
	count = 1, dot_slash_status;
	int *num = &num_of_tokens;

	while (status)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		buffer = save_buffer();
		if (buffer == NULL)
			continue;
		buffer = checkspaces(buffer);
		if (buffer == NULL)
			continue;
		args = split_buffer(buffer, num, count, av);
		if (args == NULL)
		{
			free(buffer), free(args);
			continue;
		}
		dot_slash_status = check_dot_slash(args, count, av, buffer);
		if (dot_slash_status == 1)
			continue;
		check = check_path(args);
		if (check == 1)
		{
			strPath = find_path(environ, args);
			if (strPath == NULL)
			{
				perror(args[0]);
				free_memory(args, strPath, buffer);
				continue;
				/*exit(127);*/
			}
		}
		process = execute(args, av, environ, strPath, buffer, check);
		count++, check = 0;
	}
	return (process);
}
