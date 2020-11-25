#include "shell.h"
/**
 * save_buffer - function that saves buffer
 * Return: a double pointer with the buffer
 */
char *save_buffer(void)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t n;

	n = getline(&buffer, &size, stdin);
	if (n == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffer);
		exit(0);
	}
	if (n == 1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[n - 1] = '\0';
	return (buffer);
}
