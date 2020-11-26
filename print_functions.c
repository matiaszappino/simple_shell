#include "shell.h"
/**
 * print_number - Prints integers.
 * @n: Integer to be printed.
 */

void print_number(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}

	if ((num / 10) > 0)
		print_number(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - function to print a string
 * @str: variable
 * Return: no return
 */
void _puts(char *str)
{
	int a = 0;

	for ( ; *(str + a) != '\0' ; a++)
		_putchar(*(str + a));
}
