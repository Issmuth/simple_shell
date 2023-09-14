#include "shell.h"

/**
 * execute - executes the command
 * @shellf: shell data
 */

int execute(shell_info shellf)
{
	pid_t pid;
	int exec_stat;
	char *loop;

	if (shellf.args == NULL)
		return (-1);

	if (shellf.args[0] == NULL)
	{
		free(shellf.args);
		return (-1);
	}

	loop = _itoa(shellf.loop_count);
	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		return (-1);
	}

	if (pid == 0)
	{
		execve((shellf.args)[0], shellf.args, environ);
		if (errno == EACCES)
		{
			exec_stat = 126;
			write(STDERR_FILENO, shellf.name, _strlen(shellf.name));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, loop, _strlen(loop));
			write(STDERR_FILENO, ": ", 2);
			perror(shellf.args[0]);
		} else
		{
			exec_stat = errno;
			perror(shellf.args[0]);
		}
		free(loop);
		freedom(shellf);
		exit(exec_stat);
	} else
	{
		wait(&(shellf.stat));
		if (WIFEXITED(shellf.stat))
			shellf.stat = WEXITSTATUS(shellf.stat);
	}
	free(loop);
	freedom(shellf);
	return (shellf.stat);
}
