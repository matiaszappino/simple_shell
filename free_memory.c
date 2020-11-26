#include "shell.h"
/**
 * free_memory - free memory
 * @args: arguments
 *@path: path of command
 *@buffer: buffer
 * Return: void
 */
void free_memory(char **args, char *path, char *buffer)
{
	free(args);
	free(buffer);
	free(path);
}
