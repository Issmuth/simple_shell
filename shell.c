#include "shell.h"

/**
 * count_env - counts the number of
 * environment when the program starts
 * 
 * Return: number of env
 */

int count_env(void)
{
	int i = 0;

	while(environ[i])
		i++;

	return (i);
}

/**
 * main - initializes shell info
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
	shellf.init_env = count_env();
	shellf.pid = getpid();
	looper(shellf);
	
	return (0);
}

