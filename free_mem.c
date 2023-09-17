#include "shell.h"

/**
 * freedom - frees the structure pointer
 * @shellf: shell info struct
 */

void freedom(shell_info shellf)
{
	int i = 0;

	while ((shellf.args)[i])
	{
		free((shellf.args)[i]);
		i++;
	}
	free((shellf.args)[i]);
	free(shellf.args);
}

/**
 * free_env - frees environment variable
 * list
 * @shellf: shellf info
 */

void free_env(shell_info shellf)
{
	int i = 0;

	while ((shellf.env)[i])
		i++;

	if (environ[i] == NULL)
		return;

	i--;
	while (environ[i])
	{
		free(environ[i]);
		i++;
	}
	free(environ[i]);
}
