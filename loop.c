/**
 * loop - loop.
 * @av: name of the program passed.
 * Return: 0 to EXIT_SUCCESS.
 */
#include "shell.h"
int loop(char *av)
{
	char *buffer = NULL;
	char **args = NULL;
	int num_of_tokens = 0;
	int *num = &num_of_tokens;
	char *strPath = NULL;
	int status = 1, process = 0, count = 1;

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
			free(buffer);
			free(args);
			continue;
		}
		strPath = find_path(environ, args);
		process = execute(args, av, environ, strPath, buffer, count);
		count++;
	}
	return (process);
}
