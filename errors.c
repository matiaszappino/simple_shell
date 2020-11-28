#include "shell.h"
/**
 * print_error - prints the error
 * @argv: argument list
 * @count: count of commands
 * @error_name: error message.
 * @name: name of the program.
 * Return: Nothing.
 */
void print_error(char *argv, int count, char *error_name, char *name)
{
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	print_number(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_name, _strlen(error_name));
	write(STDERR_FILENO, "\n", 1);
}

void print_error2(char *argv, int count, char *error_name, char* num, char *name)
{
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	print_number(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, argv, _strlen(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_name, _strlen(error_name));
	write(STDERR_FILENO, num, _strlen(num));
	write(STDERR_FILENO, "\n", 1);
}