#include "shell.h"
/**
 * _strcmp - function to compare two strings
 * @s1: string compared
 * @s2: string compared
 * Return:  0 if they are the same and -1 if not
 */
int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}
/**
 * _strlen - function to know the length of the string
 * @s: string
 * Return:  length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
/**
 * _strcpy - copies string pointed to by src
 * @dest: character pointer
 * @src: character source
 * Return: the pointer to des
 */
char *_strcpy(char *dest, char *src)
{
	int i;  for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}   dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - function concatenates two strings
 * @dest: string of destination
 * @src: string of source
 * Return:  dest - strings concatenated
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int x = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[x] != '\0')
	{
		dest[i] = src[x];
		x++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncmp - function to compare two strings with a certain amount of bytes
 * @s1: string compared
 * @s2: string compared
 * @len: amount of bytes to be compare
 * Return: 0 if they are the same and -1 if not
 */

int _strncmp(char *s1, char *s2, int len)
{
	int a = 0;

	while (a < len)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}
