#include "shell.h"
/**
 * find_path - function to get the PATH env
 * @args: command to be matched with the path
 * @environ: environ double pointer
 * Return:  the PATH in a string.
 */
char *find_path(char **environ, char **args)
{
	int n = 0, i = 0;
	char *path = NULL, *folder = NULL;

	if (!environ[i])
		return (NULL);

	while (environ[i])
	{
		if (_strcmp("PATH=", environ[i]) == 0)
		{
			n = _strlen(environ[i]);
			path = malloc(sizeof(char) * n - 4);
			if (!path)
				return (NULL);
			path = _strcpy(path, (environ[i] + 5));
		}
		i++;
	}
	if (path != NULL)
	{
		folder = split_path(path, args);
		free(path);
		return (folder);
	}
	return (NULL);
}
