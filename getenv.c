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
