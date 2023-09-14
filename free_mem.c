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
