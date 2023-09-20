#include "shell.h"

/**
 * executeEnvCommand - Prints the environment variables
 * @shellf: shell info
 *
 * Return: 1 when success
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
 * sh_setenv - setenv replica
 * @shellf: shell info
 *
 * Return: 1 on success 0 otherwise
 */

int sh_setenv(shell_info __attribute__((unused)) shellf)
{
	if (!(shellf.args[1]) || !(shellf.args[2]))
	{
		write(STDERR_FILENO, "setenv: missing arguments\n", 26);
		return (-1);
	}
	_setenv(shellf.args[1], shellf.args[2]);
	return (1);
}

/**
 * sh_unsetenv - unsets an environment variable
 * @shellf: shell info
 *
 * Return: 1 on success
 */

int sh_unsetenv(shell_info __attribute__((unused))shellf)
{
	if (!(shellf.args[1]))
	{
		write(STDERR_FILENO, "unsetenv: missing arguments\n", 26);
		return (-1);
	}
	unsetenv(shellf.args[1]);
	return (1);
}
