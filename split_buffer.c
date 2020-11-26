#include "shell.h"
/**
 * split_buffer - function separate the string in tokens
 * @pbuffer: string
 * @num: number
 * @av: name of program
 * @count:history count
 * Return: a double pointer with tokens
 */
char **split_buffer(char *pbuffer, int *num, int count, char *av)
{
	char *token = NULL;
	unsigned int i = 0;
	char **tokens = NULL;

	token = strtok(pbuffer, " ");
	if (search_builtin(token, tokens, pbuffer, av, count) != 0)
	{
		tokens = malloc(sizeof(char *) * BUFFSIZE);
		if (!tokens)
			return (NULL);

		while (token != NULL)
		{
			tokens[i] = token;
			i++;
			*(num) = i;
			token = strtok(NULL, " ");
		}
		tokens[i] = NULL;
		free(token);
		return (tokens);
	}
	return (tokens);
}
