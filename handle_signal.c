#include "shell.h"

/**
 * sig_handle - handles CTRL + C
 * @s: signal
 */

void sig_handle(int s)
{
	(void)s;

	write(STDOUT_FILENO, "\n$ ", 3);
}
