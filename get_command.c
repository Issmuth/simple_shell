#include "shell.h"

/**
 * get_command - gets command from user
 * @sig: pointer to an integer to signify EOF
 *
 * Return: command
 */

char *get_command(int *sig)
{
	char *command = NULL;
	unsigned long int len = 0;

	*sig = getline(&command, &len, stdin);

	return (command);
}
