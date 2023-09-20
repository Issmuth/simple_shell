#include "shell.h"

char *_getenv(char *name)
{
	int i = 0, j = 0, k = 0;
	char *value;

	if (name == NULL)
		return (NULL);

	while (environ[i][j] != '=')
	{

		if (environ[i][j] != name[j])
		{
			j = 0;
			i++;
			if (environ[i] == NULL)
				break;

			continue;
		} 
		j++;
	}

	if (environ[i] == NULL)
		return (NULL);

	while(environ[i][j] != '=')
		j++;

	value = malloc(sizeof(char) * (_strlen(environ[i]) - j));
	if (value == NULL)
		return (NULL);

	j++;
	while (environ[i][j])
	{
		value[k] = environ[i][j];
		j++;
		k++;
	}
	value[k] = '\0';
	return (value);
}

int _setenv(char *name, char *value)
{
	char *temp = NULL, *val;
	int i = 0, is_overwrite = 0;

	if ((val = _getenv(name)) != NULL)
	{
		is_overwrite = 1;
		temp = malloc(sizeof(char) * (_strlen(val) + _strlen(name) + 2));
                if (temp == NULL)
                        return (-1);
                _strcpy(temp, name);
                _strcat(temp, "=");
                _strcat(temp, val);
                while (environ[i])
                {
                        if (_strcmp(temp, environ[i]) == 0)
                                break;
                        i++;
                }
        }
	environ[i] = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
        if (environ[i] == NULL)
                return (-1);

        _strcpy(environ[i], name);
        _strcat(environ[i], "=");
        _strcat(environ[i], value);

        if (!is_overwrite)
                environ[i + 1] = NULL;

        free(val);
	if (temp)
	        free(temp);
        return (1);
}
/*
int _unsetenv(const char *name)
{
	int i = 0, j = 0, k = 0, len = 0;
	char *temp, *temp2, **new_env;

	temp = _getenv(shellf.args[1]);
        if (temp == NULL)
        {
                write(STDERR_FILENO, "unsetenv: ", 10);
                write(STDERR_FILENO, shellf.args[1], _strlen(shellf.args[1]));
                write(STDERR_FILENO, ": not found\n", 12);
                return (-1);
        }
        temp2 = malloc(sizeof(char) * (_strlen(temp) + _strlen(shellf.args[1]) + 2));
        if (temp2 == NULL)
                return (-1);
	_strcpy(temp2, shellf.args[1]);
        _strcat(temp2, "=");
        _strcat(temp2, temp);
        while (environ[len])
                len++;
        new_env = malloc(sizeof(char *) * (len + 1));
        if (new_env == NULL)
                return (-1);

        while (environ[i])
        {
                if (_strcmp(environ[i], temp2) == 0)
                        break;

                i++;
        }
*/
