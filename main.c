#include "shell.h"
/**
 * main - function to start a shell in linux.
 * @ac: argument counter.
 * @av: variable arguments.
 * Return:  0 Success
 */
int main(int ac, char **av)
{
	int outstatus;
	(void)ac;

	signal(SIGINT, kill_signal);
	outstatus = loop(av[0]);
	return (outstatus);
}
