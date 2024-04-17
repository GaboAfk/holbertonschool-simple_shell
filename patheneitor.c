/*
* File: patheneitor.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/
#include "zzz.h"

/**
 * _getenv - search path in environ
 * @name: PATH to find
 * Return: PATH of @name of NULL
 */
char *_getenv(char *name)
{
	int i = 0;
	char **env = environ;
	size_t name_len = strlen(name);

	while (env[i])
	{
		if ((strncmp(env[i], name, name_len) == 0) && (env[i])[name_len] == '=')
			return (&((env[i])[name_len + 1]));
		i++;
	}
	return (NULL);
}

/**
 * get_dir - search a valid directory for @function and return a new PATH
 * @function: entry function
 */
void get_dir(char **function)
{
	char *directories, path[1024], **array_dir;
	int i = 0;
	struct stat st;

	if (stat(*function, &st) == 0)
		return;

	directories = _getenv("PATH");
	array_dir = split_str(directories, ":");

	i = 0;
	while (array_dir && array_dir[i])
	{
		memset(path, 0, sizeof(path));

		strcat(path, array_dir[i]);
		strcat(path, "/");
		strcat(path, *function);

		if (stat(path, &st) == 0)
		{
			free (*function);
			*function = NULL;
			*function = strdup(path);
			if (!function)
			{
				printf("Error realloc\n");
				break;
			}
			break;
		}
		i++;
	}
	i = 0;
	while (array_dir && array_dir[i])
	{
		free(array_dir[i]);
		i++;
	}
	free(array_dir);
}
