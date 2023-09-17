#include "shell.h"

/**
 * rmvar - removes $ sign from string
 * @str: string
 *
 * Return: altered string.
 */

char *rmvar(char *str)
{
	int i = 1, j = 0, len;
	char *new;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	new = malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);

	while (str[i])
	{
		new[j] = str[i];
		j++;
		i++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}
/**
 * variable - handles variables in
 * the environmner
 * @shellf: shell info
 */

void variable(shell_info shellf)
{
	int i = 0;
	char *str;
	
	if (!(shellf.args))
		return;

	while (shellf.args[i])
	{
		if (shellf.args[i][0] == '$')
		{
			str = rmvar(shellf.args[i]);
			shellf.args[i] = _getenv(str);
			free(str);
		}
		i++;
	}
}

