#include "shell.h"

/**
 * main - initializes shell info
 * and starts loop
 *
 * Return: exit stat
 */

int main(void)
{
	shell_info *shellf;
	int stat;

	signal(SIGINT, sig_handle);

	shellf = malloc(sizeof(shell_info));

	shellf->command = NULL;
	shellf->args = NULL;
	shellf->loop_count = 1;
	shellf->stat = 0;
	looper(shellf);

	stat = shellf->stat;

	free(shellf);
	return (stat);
}

