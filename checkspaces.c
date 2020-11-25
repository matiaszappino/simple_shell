#include "shell.h"
/**
 *checkspaces - check for spaces in buffer
 *@buffer: buffer
 *Return: buffer
 */
char *checkspaces(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] != ' ')
			return (buffer);
		i++;
	}
	free(buffer);
	return (NULL);
}
