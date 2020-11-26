#include "shell.h"
/**
 * kill_signal - handle ctrl C
 * @sig: signal integer
 * Return: 0 if token was not found
 */
void kill_signal(int sig)
{
	(void)sig;
	signal(SIGINT, kill_signal);
	write(STDIN_FILENO, "\n$ ", 3);
}
