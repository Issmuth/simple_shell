#include "shell.h"

/**
 * looper - starts the shell loop
 * @shellf: pointer to a struct that
 * contains shell info
 */

void looper(shell_info *shellf)
{
	int loop, sig_eof = 1;
	
	shellf->pid = getpid();
	loop = 1;
	while (loop)
	{
		write(STDOUT_FILENO, "$ ", 2);
		shellf->command = get_command(&sig_eof);
		if (sig_eof == EOF)
		{
			free(shellf->command);
			write(STDOUT_FILENO, "\n", 1);
			return;
		} else
		{
			shellf->args = tokenize(shellf->command);
			execute(shellf);
			shellf->loop_count += 1;
		}
	}
}
