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
	int status;
	builtin op_func[] = {{"exit", builtin_exit},
						 {"env", builtin_env}, {"help", builtin_help},
						 {NULL, NULL}};

	while (op_func[j].reference != NULL)
	{
		if (_strcmp(token, op_func[j].reference) == 0 &&
		    (_strlen(token) == _strlen(op_func[j].reference)))
		{
			status = op_func[j].function(token, tokens, pbuffer, av, count);
			if (status != 0)
				return (0);
			else if (status == 1)
				return (1);
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
	int n, status, counter = 0;
	int *pcounter = &counter;

	tokens = NULL;
	if (!token)
		return (0);
	n = _strlen(token);
	if (n == 4)
	{
		if (!_strncmp("exit", token, 4))
		{
			tokens = malloc(sizeof(char *) * BUFFSIZE);
			if (!tokens)
				return (0);
			tokens = tokenize(token, tokens, pcounter);
			
			if (counter == 1 && tokens[1] == NULL)
			{
				free(tokens);
				free(pbuffer);
				exit(EXIT_SUCCESS);
			}
			if (counter == 2 && tokens[2] == NULL && _atoi(tokens[1]) >= 0)
			{
				status = _atoi(tokens[1]);
				free(tokens);
				free(pbuffer);
				exit(status);
			}
			if (counter == 2 && _atoi(tokens[1]) < 0)
			{
				print_error2(tokens[0], count, "Illegal number: ", tokens[1], av);
				free(tokens);
				return (2);
			}
			if (counter > 2)
			{
				print_error(tokens[0], count, "too many arguments", av);
				free(tokens);
				return (1);
			}
			
		}
	}
	free_memory(tokens, pbuffer, token);
	perror(av);
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
				free(tokens);
			}
			return (1);
		}
	return (0);
}
/**
 * helpBuiltIn - finds the desired help page of the builtin
 * @file: a string of the desired help page
 *
 * Return: 1 if page found and -1 if no page is found
 */
int builtin_help(char *token, char **tokens)
{
	int n, counter = 0;
	int *pcounter = &counter;

	tokens = NULL;
	if (!token)
		return (0);
	n = _strlen(token);
	if (n == 4)
	{
		if (!_strncmp("help", token, 4))
		{
			tokens = malloc(sizeof(char *) * BUFFSIZE);
			if (!tokens)
				return (0);
			tokens = tokenize(token, tokens, pcounter);

			if (tokens[1] == NULL)
			{
				_puts("Select a built-in: env, exit\n");
				free(tokens);
				return (1);
			}
			if (_strcmp(tokens[1], "exit") == 0)
			{
				help_Exit();
				free(tokens);
				return (1);
			}
			else if (_strcmp(tokens[1], "env") == 0)
			{
				help_Env();
				free(tokens);
				return (1);
			}
		
			else if (_strcmp(tokens[1], "help") == 0)
			{
				help_Help();
				free(tokens);
				return (1);
			}
				
			else
			{
				_puts("Not a built-in of simple_shell.\n");
				free(tokens);
				return (1);
			}
		}
	}
	return (0);
}