#include "shell.h"
/**
 * execute - function that execute all arguments in command line.
 * @args: Arguments typed into the line command.
 * @env_var: env variable
 * @path: path of the program.
 * @av: command
 * @buffer: buffer
 * @check: if args[0] or path will be used
* Return: No return.
 */
int execute(char *args[], char *av, char **env_var,
char *path, char *buffer, int check)
{
	pid_t pid;
	int status, outstatus = 0;
	char *command;

	if (check == 1)
		command = path;
	else
		command = args[0];
	pid = fork();
	if (pid < 0)
		exit(errno);
	if (pid == 0)
	{
		if (execve(command, args, env_var) == -1)
		{
			/*print_error(command, count, "cannot execute", av);*/
			perror(av);
			free_memory(args, path, buffer);
			exit(126);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			outstatus = WEXITSTATUS(status);
	}
	if (check == 1)
		free_memory(args, path, buffer);
	else
	{
		free(args);
		free(buffer);
	}
	return (outstatus);
}
