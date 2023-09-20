#include "shell.h"

/**
 * exit_func - exit function
 * @shellf: shellf info including exit status
 *
 * Return: error no if fail
 */

int exit_func(shell_info __attribute__((unused)) shellf)
{
	int stat;
	char *loop;

	loop = _itoa(shellf.loop_count);
	if (shellf.args[1] != NULL)
	{
		stat = _atoi(shellf.args[1]);
		if (stat < 0 || _strlen(shellf.args[1]) > 10)
		{
			write(STDERR_FILENO, shellf.name, _strlen(shellf.name));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, loop, _strlen(loop));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, shellf.args[0], _strlen(shellf.args[0]));
			write(STDERR_FILENO, ": Illegal number: ", 18);
			write(STDERR_FILENO, shellf.args[1], _strlen(shellf.args[1]));
			write(STDERR_FILENO, "\n", 1);
			free(loop);
			return (2);
		}
		if (stat >= 256)
			shellf.stat = (stat % 256);
		else
			shellf.stat = stat;
	}
	free(loop);
	freedom(shellf);
	free_env(shellf);
	exit(shellf.stat);
}
