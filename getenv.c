#include "shell.h"

/**
 * _getenv - search for an environment varaibale
 * @name: name of the variable
 *
 * Return: the value
 */

char *_getenv(char *name)
{
	int i = 0, j = 0, k = 0;
	char *value;

	if (name == NULL)
		return (NULL);

	while (environ[i][j] != '=')
	{

		if (environ[i][j] != name[j])
		{
			j = 0;
			i++;
			if (environ[i] == NULL)
				break;

			continue;
		}
		j++;
	}

	if (environ[i] == NULL)
		return (NULL);

	while (environ[i][j] != '=')
		j++;

	value = malloc(sizeof(char) * (_strlen(environ[i]) - j));
	if (value == NULL)
		return (NULL);

	j++;
	while (environ[i][j])
	{
		value[k] = environ[i][j];
		j++;
		k++;
	}
	value[k] = '\0';
	return (value);
}

/**
 * _setenv - set an environment variable
 * @name: name
 * @value: value
 *
 * Return: 1 on success
 */

int _setenv(char *name, char *value)
{
	char *temp = NULL, *val;
	int i = 0, is_overwrite = 0;

	val = _getenv(name);
	if (val != NULL)
	{
		is_overwrite = 1;
		temp = malloc(sizeof(char) * (_strlen(val) + _strlen(name) + 2));
		if (temp == NULL)
			return (-1);
		_strcpy(temp, name);
		_strcat(temp, "=");
		_strcat(temp, val);
		while (environ[i])
		{
			if (_strcmp(temp, environ[i]) == 0)
				break;
			i++;
		}
	} else
	{
		while (environ[i])
			i++;
	}
	environ[i] = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	if (environ[i] == NULL)
		return (-1);

	_strcpy(environ[i], name);
	_strcat(environ[i], "=");
	_strcat(environ[i], value);

	if (!is_overwrite)
		environ[i + 1] = NULL;

	free(val);
	if (temp)
		free(temp);
	return (1);
}
