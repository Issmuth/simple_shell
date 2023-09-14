#include "shell.h"

/**
 * print_err - prints error in sh format
 * @shellf: shell info
 */

void print_err(shell_info shellf)
{
	char *err_message ,*loop;
	int buff_size;

	loop = _itoa(shellf.loop_count);
	buff_size = _strlen(shellf.args[0]) + _strlen(shellf.name) + _strlen(loop) + 17;
	err_message = malloc(sizeof(char) * buff_size);
	if (err_message == NULL)
		return;
	
	_strcpy(err_message, shellf.name);
	_strcat(err_message, ": ");
	_strcat(err_message, loop);
	_strcat(err_message, ": ");
	_strcat(err_message, shellf.args[0]);
	_strcat(err_message, ": not found\n");

	write(STDERR_FILENO, err_message, _strlen(err_message));
	free(err_message);
	free(loop);
}
