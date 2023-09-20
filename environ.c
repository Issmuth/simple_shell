#include "shell.h"

/**
 *  executeEnvCommmand - Prints the environment variables
 *  @shellf: shell info
 *
 *  Return: 1 when success
 */

int executeEnvCommand(shell_info __attribute__((unused)) shellf)
{
	int i = 0;
	char **env = environ;

	while (env[i])
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}

/**
 * _setenv - setenv replica
 * @shellf: shell info
 *
 * Return: 1 on success 0 otherwise
 */

int sh_setenv(shell_info __attribute__((unused)) shellf)
{
/*	int i = 0, is_overwrite = 0;
	char *temp, *val;*/

	if (!(shellf.args[1]) || !(shellf.args[2]))
	{
		write(STDERR_FILENO, "setenv: missing arguments\n", 26);
		return (-1);
	}
	_setenv(shellf.args[1], shellf.args[2]);
	return (1);
}
/*	if ((val = _getenv(shellf.args[1])) != NULL)
	{
		is_overwrite = 1;
		temp = malloc(sizeof(char) * (_strlen(val) + _strlen(shellf.args[1]) + 2));
		if (temp == NULL)
			return (-1);
		_strcpy(temp, shellf.args[1]);
		_strcat(temp, "=");
		_strcat(temp, val);
		while (environ[i])
		{
			if (_strcmp(temp, environ[i]) == 0)
				break;
			i++;
		}
	}

	environ[i] = malloc(sizeof(char) * (_strlen(shellf.args[1]) + _strlen(shellf.args[2]) + 2));
	if (environ[i] == NULL)
		return (-1);

	_strcpy(environ[i], shellf.args[1]);
	_strcat(environ[i], "=");
	_strcat(environ[i], shellf.args[2]);

	if (!is_overwrite)
		environ[i + 1] = NULL;

	free(val);
	free(temp);
	return (1);
}

int sh_unsetenv(shell_info __attribute__((unused))shellf)
{
	int i = 0, j = 0, k = 0, len = 0;
	char *temp, *temp2, **new_env;

	if (!(shellf.args[1]))
	{
		write(STDERR_FILENO, "unsetenv: missing arguments\n", 26);
		return (-1);
	}
	temp = _getenv(shellf.args[1]);

	if (temp == NULL)
	{
		write(STDERR_FILENO, "unsetenv: ", 10);
		write(STDERR_FILENO, shellf.args[1], _strlen(shellf.args[1]));
		write(STDERR_FILENO, ": not found\n", 12);
		return (-1);
	}
	temp2 = malloc(sizeof(char) * (_strlen(temp) + _strlen(shellf.args[1]) + 2));
	if (temp2 == NULL)
		return (-1);

	_strcpy(temp2, shellf.args[1]);
	_strcat(temp2, "=");
	_strcat(temp2, temp);
	while (environ[len])
		len++;
	new_env = malloc(sizeof(char *) * (len + 1));
	if (new_env == NULL)
		return (-1);

	while (environ[i])
	{
		if (_strcmp(environ[i], temp2) == 0)
			break;

		i++;
	}
	
	while (environ[j])
	{
		if (j = i)
		{
			j++;
*/
