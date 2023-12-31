#include "shell.h"

/**
 * check_builtins - execute a builtin command
 * if it exists
 * @shellf: shell info
 *
 * Return: 1 if executed successfully 0 if not
 */

int check_builtins(shell_info shellf)
{
	int i;
	builtin built_ins[] = {
		{"exit", exit_func},
		{"env", executeEnvCommand},
		{"setenv", sh_setenv},
		{"unsetenv", sh_unsetenv},
		{"cd", cd},
		{NULL, NULL}
	};

	if (shellf.args == NULL || shellf.args[0] == NULL)
		return (0);

	for (i = 0; built_ins[i].command != NULL; i++)
	{
		if (!(strcmp(built_ins[i].command, shellf.args[0])))
			return (built_ins[i].func(shellf));
	}
	return (0);
}
