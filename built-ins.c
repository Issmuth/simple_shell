#include "shell.h"

/**
 * chech_builtins - execute a builtin command
 * if it exists
 * @shellf: shell info
 *
 * Return: 1 if executed 0 if not
 */

int check_builtins(shell_info shellf)
{
	int i;
	builtin built_ins[] = {
		{"exit", exit_func},
		{NULL, NULL}
	};

	if (shellf.args == NULL || shellf.args[0] == NULL )
		return (0);

	for (i = 0; built_ins[i].command != NULL; i++)
	{
		if (!(strcmp(built_ins[i].command, shellf.args[0])))
		{
			shellf.stat = built_ins[i].func(shellf);
			return (1);
		}
	}
	return (0);
}
