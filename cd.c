#include "shell.h"

/**
 * get_cwd - get current working directory
 * 
 * Return: pointer to character
 * containing current directrory path
 */

char *get_cwd(void)
{
	size_t buff_size = 256;
	char *temp_dir, *cur_dir;

	temp_dir = malloc(sizeof(char) * buff_size);
	while (1)
	{
		getcwd(temp_dir, buff_size);
		if (temp_dir == NULL)
		{
			buff_size *= 2;
			if(realloc(temp_dir, (buff_size * sizeof(char))) == NULL)
			{
				perror("./hsh");
				return (NULL);
			}
			continue;
		} else
			break;
	}
	cur_dir = _strdup(temp_dir);
	free(temp_dir);
	return (cur_dir);
}

/**
 * cd - changes working directory
 * @shellf: shell info
 *
 * Return: 1 if sucessfull
 */

int cd(shell_info __attribute__((unused)) shellf)
{
	char *home, *pwd, *oldpwd, *temp_path;

	pwd = _getenv("PWD");
	if (pwd == NULL)
		return (-1);

	oldpwd = _getenv("OLDPWD");
	if (oldpwd == NULL)
		return (-1);

	home = _getenv("HOME");
	if (pwd == NULL)
		return (-1);

	if (shellf.args[1] == NULL || !(_strcmp(shellf.args[1], "~")))
	{
		chdir(home);
		setenv("PWD", home, 1);
		setenv("OLDPWD", pwd, 1);
		free(home), free(pwd), free(oldpwd);
		return (1);
	}

	if (_strcmp(shellf.args[1], "-") == 0)
	{
		chdir(oldpwd);
		write(STDOUT_FILENO, oldpwd, _strlen(oldpwd));
		write(STDOUT_FILENO, "\n", 1);
		setenv("PWD", oldpwd, 1);
		setenv("OLDPWD", pwd, 1);
		free(home), free(pwd), free(oldpwd);
		return (1);
	}
	temp_path = malloc(sizeof(char) * (_strlen(shellf.args[1]) + 2));
	_strcpy(temp_path, shellf.args[1]);
	_strcat(temp_path, "/");
	if (chdir(shellf.args[1]) == 0)
	{
		setenv("PWD", shellf.args[1], 1);
		setenv("OLDPWD", pwd, 1);
	} else
	{
		write(STDERR_FILENO, "not found\n", 10);
	}
	free(home), free(pwd), free(oldpwd), free(temp_path);
	return (-1);
}
