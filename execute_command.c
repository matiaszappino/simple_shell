#include "shell.h"
/**
 * execute - function that execute all arguments in command line.
 * @args: Arguments typed into the line command.
 * @env_var: env variable
 * @path: path of the program.
 * @av: command
 * @buffer: buffer
 * @count: history count
 * Return: No return.
 */
int execute(char *args[], char *av, char **env_var,
char *path, char *buffer, int count)
{
	pid_t pid;
	int status, outstatus = 0;
	int flag = 0, stat;

	pid = fork();
	if (pid < 0)
		exit(errno);
	if (pid == 0)
	{
		check_dot_slash(args, count, path, av, buffer);
		if (execve(args[0], args, env_var) == -1)
		{
			stat = execve(path, args, env_var);
			if  (stat != -1)
				flag = 1;
			if (flag == 1)
			{
				print_error(args[0], count, "cannot execute", av);
				free_memory(args, path, buffer);
				exit(126);
			}
			else
			{
				print_error(args[0], count, "command not found", av);
				free_memory(args, path, buffer);
				exit(127);
			}
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			outstatus = WEXITSTATUS(status);
	}
	free_memory(args, path, buffer);
	return (outstatus);
}
