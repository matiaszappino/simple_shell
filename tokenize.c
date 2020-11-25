#include "shell.h"
/**
 * tokenize - tokenize function
 * @token: token
 * @tokens: double pointer to tokens
 * @count: count of history
 * Return: tokens
 */
char **tokenize(char *token, char **tokens, int *count)
{
	int i = 0;

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		(*count)++;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
