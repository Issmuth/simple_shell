#include "shell.h"

/**
 * tokenize - split the command and arguments
 * into tokens and stores in a vector
 * @command: string to tokenize
 *
 * Return: tokenized array of strings
 */

char **tokenize(char *command)
{
	char *token = NULL, *temp = NULL,
	     *delim = " \t\n\a";
	char **args = NULL;
	int i = 0, counter = 0;

	if (command == NULL)
		return (NULL);

	if (_strcmp(command, "\n") == 0)
	{
		free(command);
		return (NULL);
	}

	temp = _strdup(command);
	token = strtok(command, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		counter++;
	}

	args = malloc(sizeof(char *) * (counter + 1));
	if (args == NULL)
		return (NULL);

	token = strtok(temp, delim);
	while (token)
	{
		args[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy(args[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	free(temp);
	free(command);
	return (args);
}
