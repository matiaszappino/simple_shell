#include "shell.h"
/**
 * prompt - Prints our prompt line.
 * Return: Nothing.
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
