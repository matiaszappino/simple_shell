#include "shell.h"
/**
 * search_builtin - searches token in builtin functions
 * @token: token
 * @tokens: double pointer to tokens
 * @pbuffer: buffer
 * @av: name of program
 * @count: count of history
 * Return: 1 if token was not found, 0 if command was founded
 */
int search_builtin(char *token, char **tokens, char *pbuffer,
char *av, int count)
{
	unsigned int j = 0;
	builtin op_func[] = {{"exit", builtin_exit},
			     {"env", builtin_env}, {NULL, NULL}};

	while (op_func[j].reference != NULL)
	{
		if (_strcmp(token, op_func[j].reference) == 0
		    && (_strlen(token) == _strlen(op_func[j].reference)))
		{
			op_func[j].function(token, tokens, pbuffer, av, count);
			return (0);
		}
		j++;
	}
	return (1);
}

/**
 * builtin_exit - exit builtin function
 * @token: token
 * @tokens: double pointer to tokens
 * @pbuffer: buffer
 * @av: name of program
 * @count: count of history
 * Return: exit
 */
int builtin_exit(char *token, char **tokens,
char *pbuffer, char *av, int count)
{
	int n, status, i = 0;

	tokens = NULL;
	n = _strlen(token);
	if (n == 4)
	{
		if (!_strncmp("exit", token, 4))
		{
			tokens = malloc(sizeof(char *) * BUFFSIZE);
			if (!tokens)
				return (EXIT_FAILURE);
			while (token != NULL)
			{
				tokens[i] = token;
				i++;
				token = strtok(NULL, " ");
			}
			tokens[i] = NULL;
			if (tokens[1] == NULL)
			{
				free_memory(tokens, token, pbuffer);
				exit(1);
			}
			else if (tokens[2] == NULL)
			{
				status = _atoi(tokens[1]);
				free_memory(tokens, token, pbuffer);
				exit(status);
			}
			else
			{
				print_error(tokens[0], count, "too many arguments", av);
				free(tokens);
				return (0);
			}
		}
	}
	return (0);
}

/**
 * builtin_env - prints env builtin function
 * @token: token
 * @tokens: double pointer to tokens
 * Return: 1 on success, 0 on error
 */
int builtin_env(char *token, char **tokens)
{
	int i = 0, n = 0;

	n = _strlen(token);
	if (n == 3)
		if ((_strncmp("env", token, 3)) == 0)
		{
			while (environ[i] != NULL)
			{
				_puts(environ[i]);
				_putchar(10);
				i++;
			}
			return (1);
		}
		return (0);
}
