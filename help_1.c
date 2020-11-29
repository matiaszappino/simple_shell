#include "shell.h"
/**
 * help_Exit - prints the exit help page.
 */
void help_Exit(void)
{
	_puts("exit: exit [n]\n\n");

	_puts("  Exit the shell.\n\n");

	_puts("  Exits the shell with a status of N. If N is omitted,\n");
	_puts("  the exit status is that of the last command executed\n");
}
/**
 * help_Env - prints the env help page.
 */
void help_Env(void)
{
	_puts("env: env  [-] [NAME=VALUE]... [COMMAND [ARG]...]\n\n");

	_puts("  Prints out the current environment\n\n");

	_puts("  Exit Status:\n");
	_puts("  Returns success unless an invalid option is given\n");
	_puts("  or an error occurs.\n");
}
/**
 * help_Help - prints the help... help...
 */
void help_Help(void)
{
	_puts("help: help [PATTERN ...]\n\n");

	_puts("  Display information about builtin commands.\n\n");

	_puts("  Displays brief summaries of builtin commands. If\n");
	_puts("  PATTERN is specified, gives detailed help on all\n");
	_puts("  commands matching PATTERN, otherwise the list of help\n");
	_puts("  topics is printed.\n\n");

	_puts("  Arguments:\n");
	_puts("    PATTERN: Pattern specifiying a help topic\n\n");

	_puts("  Exit Status:\n");
	_puts("    Returns success unless PATTERN is not found or an\n");
	_puts("    invalid option is given.\n");
}