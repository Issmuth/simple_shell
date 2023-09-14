#include "shell.h"

/**
 * exit_func - exit function
 * @shellf: shellf info including exit status
 */

int exit_func(shell_info __attribute__((unused)) shellf)
{
	int stat;
	char *loop;

	loop = _itoa(shellf.loop_count);
	if (shellf.args[1] != NULL)
	{
		stat = _atoi(shellf.args[1]);
		if (stat < 0)
		{
			write(STDERR_FILENO, shellf.name, _strlen(shellf.name));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, loop, _strlen(loop));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, shellf.args[0], _strlen(shellf.args[0]));
			write(STDERR_FILENO, ": Illegal number: ", 18);
			write(STDERR_FILENO, shellf.args[1], _strlen(shellf.args[1]));
			write(STDERR_FILENO, "\n", 1);
			return (2);
		} else
			shellf.stat = stat;
	}
	freedom(shellf);
	exit(shellf.stat);
}
			
