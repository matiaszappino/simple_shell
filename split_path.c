#include "shell.h"
/**
 * split_path - function to split the path
 * @path: path to the command
 * @args: program and arguments passed
 * Return:  the path with the command in a string.
 */
char *split_path(char *path, char **args)
{
	char *folder = NULL;
	struct stat fileStat;
	char *command = malloc(sizeof(char) * _strlen(args[0]) + _strlen(path));
	if (!command)
		return (NULL);

	folder = strtok(path, ":");
	while (folder != NULL)
	{
		command[0] = '\0';
		command = _strcat(command, folder);
		command = _strcat(command, "/");
		command = _strcat(command, args[0]);
		if (stat(command, &fileStat) == 0)
		{
			char *final_command = malloc(sizeof(char) * _strlen(command));
			if (!final_command)
				return (NULL);
			_strcpy(final_command, command);
			free(command);
			return (final_command);
		}
				
		folder = strtok(NULL, ":");
	}
	free(command);
	free(folder);
	return (NULL);
}
