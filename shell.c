#include "shell.h"

/**
 * main - initializes shell information
 * and starts loop
 *
 * Return: exit stat
 */

int main(int __attribute__((unused)) argc, char **argv)
{
	shell_info shellf;

	signal(SIGINT, sig_handle);


	shellf.name = argv[0];
	shellf.command = NULL;
	shellf.args = NULL;
	shellf.loop_count = 1;
	shellf.stat = 0;
	shellf.mode = isatty(STDIN_FILENO);
	shellf.env = environ;
	looper(shellf);
	
	return (0);
}

