#include "shell.h"

/**
 * execute - executes the command
 * @shellf: shell data
 */

void execute(shell_info *shellf)
{
	pid_t pid;
	int exec_stat;

	if (shellf->args == NULL)
		return;

	pid = fork();
	if (pid < 0)
	{
		perror("Error:");
		return;
	}

	if (pid == 0)
	{
		exec_stat = execve((shellf->args)[0], shellf->args, environ);
		if (exec_stat < 0)
		{
			perror(shellf->args[0]);
		}
	}

	wait(&exec_stat);
	freedom(shellf);
	return;
}
