#include "shell.h"

/**
 * free_mem - frees pathlist
 * @pathlist: ...
 */

void free_mem(char **pathlist)
{
	int i = 0;

	while (pathlist[i])
	{
		free(pathlist[i]);
		i++;
	}
	free(pathlist[i]);
	free(pathlist);
}

/**
 * getpath - store the path
 * directories in arrays
 * @path: path value
 *
 * Return: pointer to pointer
 * of path directories
 */

char **getpath(char *path)
{
	int i = 0, j = 0;
	char *token, **pathlist, *delim = ":"; 

	if (path == NULL)
		return (NULL);

	while (path[i])
	{
		if (path[i] == ':')
			j++;
		i++;
	}
	pathlist = malloc(sizeof(char *) * (j + 2));
	if (pathlist == NULL)
	{
		free(path);
		return (NULL);
	}
	i = 0;
	j = 0;
	token = strtok(path, delim);
	while (token)
	{
		i = _strlen(token) + 2;
		pathlist[j] = malloc(sizeof(char) * i);
		_strcpy(pathlist[j], token);
		_strcat(pathlist[j], "/");
		token = strtok(NULL, delim);
		j++;
	}
	pathlist[j] = NULL;
	free(path);
	return (pathlist);
}

/**
 * check_path - path handler
 * @shellf: shell info
 *
 * Return: 1 if found 0 if otherwise
 */

int check_path(shell_info shellf)
{
	char *path, *temp_chain, *oldcomm;
	char **pathlist;
	int i = 0;
	struct stat fstat;
	
	if (shellf.args == NULL || shellf.args[0] == NULL)
		return (-1);

	if (stat(shellf.args[0], &fstat) == 0)
		return (1);

	path = _getenv("PATH");
	if (path == NULL)
		return (0);
	
	pathlist = getpath(path);
	if (pathlist == NULL)
		return (0);

	while (pathlist[i])
	{
		temp_chain = malloc(sizeof(char) * (_strlen(pathlist[i]) + _strlen(shellf.args[0]) + 1));
		_strcpy(temp_chain, pathlist[i]);
		_strcat(temp_chain, shellf.args[0]);
		if (stat(temp_chain, &fstat) == 0)
		{
			oldcomm = shellf.args[0];
			shellf.args[0] = temp_chain;
			free(oldcomm);
			free_mem(pathlist);
			return (1);
		}
		free(temp_chain);
		i++;
	}
	
	free_mem(pathlist);
	return (0);
}
