#include "shell.h"

/**
 * looper - starts the shell loop
 * @shellf: pointer to a struct that
 * contains shell info
 */

void looper(shell_info shellf)
{
	int loop = 1, sig_eof = 1, path_stat;

	while (loop)
	{
		if (shellf.mode == 1)
			write(STDOUT_FILENO, "$ ", 2);
		shellf.command = get_command(&sig_eof);
		if (sig_eof == -1)
		{
			free(shellf.command);
			if (shellf.mode == 1)
				write(STDOUT_FILENO, "\n", 1);
			exit(shellf.stat);
		} else
		{
			shellf.args = tokenize(shellf.command);
			variable(shellf);
			shellf.stat = check_builtins(shellf);
			if (shellf.stat != 0)
			{
				if (shellf.stat == -1 || shellf.stat == 1)
					shellf.stat = 0;
				freedom(shellf);
				shellf.loop_count += 1;
				continue;
			}
			path_stat = check_path(shellf);
			if (path_stat == 0)
			{
				print_err(shellf), freedom(shellf);
				shellf.stat = 127, shellf.loop_count += 1;
				continue;
			} else if (path_stat == -1)
			{
				free(shellf.args), shellf.loop_count += 1;
				continue;
			}
			shellf.stat = execute(shellf), shellf.loop_count += 1;
		}
	}
}
