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
	char *directories = NULL;

	while (env[i])
	//while (environ[i])
	{
		if ((strncmp(env[i], name, name_len) == 0) && (env[i])[name_len] == '=')
		{
			directories = strdup(&((env[i])[name_len + 1]));
			return (directories);
		}
//		if ((strncmp(environ[i], name, name_len) == 0) && (environ[i])[name_len] == '=')
//			return (&((environ[i])[name_len + 1]));
		i++;
	}
	return (NULL);
}

/**
 * get_dir - search a valid directory for @function and return a new PATH
 * @function: entry function
 */
int get_dir(char **function)
{
	char *directories, path[1024], **array_dir = NULL;
	int i = 0, valid_stat = 0;
	struct stat st;
	size_t k;

	if (stat(*function, &st) == 0)
		return (1);

	directories = _getenv("PATH");
	split_str2(&array_dir, directories, ":");
	free(directories);

	for (k = 0; k < 1024; k++)
			path[k] = 0;

	for (i = 0; array_dir && array_dir[i]; i++)
	{
		strcat(path, array_dir[i]);
		strcat(path, "/");
		strcat(path, *function);

		if (stat(path, &st) == 0)
		{
			valid_stat = 1;
			free(*function), *function = NULL;
			*function = strdup(path);
			if (!function)
			{
				printf("Error realloc\n");
				break;
			}
			break;
		}
//		printf("path = %s\n", path);
//		printf("strlen(path) = %ld\n", strlen(path));
			for (k = 0; k < strlen(path); k++)
			path[k] = 0;

	}
	array_in_free(array_dir);
 return (valid_stat);
}


