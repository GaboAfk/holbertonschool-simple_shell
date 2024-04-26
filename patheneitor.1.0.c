/*
* File: patheneitor.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/

#include "zzz.h"

/**
 * _getenv - search path in environ
 * @name: PATH to find
 * Return: PATH of @name or NULL
 */

char *_getenv(char *name)
{
	int i = 0;
	char **env = environ;
	size_t name_len = strlen(name);
	char *directories = NULL;

	while (env[i])
	{
		/*printf("env[%i] = %.5s name = %s len = %ld\n",i, env[i], name, name_len);*/
		if ((strncmp(env[i], name, name_len) == 0))
		/*// && (env[i])[name_len] == '=')//PATH=*/
		{
			/*printf("ENTRE A DIRECTORIOESSSSSSSSSSSS\n");*/
			directories = strdup(&((env[i])[name_len + 1]));
			if (strlen(directories) > 0)
				return (directories);
		}
		i++;
	}
	free(directories);
	return (NULL);
}

/**
 * get_dir - search a valid directory for @function
 * @function: enter and modify the value with the command directory
 * Return: 1 if the command directory is valid 0 if not
 */

int get_dir(char **function)
{
	char *directories = NULL, path[1024], **array_dir = NULL;
	int i = 0, valid_stat = 0;
	struct stat st;
	size_t k;

	if ((**function == '/' || **function == '.') && stat(*function, &st) == 0)
		return (1);

	directories = _getenv("PATH=");
	/*printf("directories = %s\n", directories);*/
	if (!directories)
		return (/*stat(*function, &st) == 0 ? 1 :*/ 0);

	split_str2(&array_dir, directories, ":");
	free(directories);
	for (k = 0; k < 1024; k++)
		path[k] = 0;
	for (i = 0; array_dir && array_dir[i]; i++)
	{
		strcat(path, array_dir[i]);
		strcat(path, "/");
		strcat(path, *function);
		/*printf("path = %s stat = %d\n", path, stat(path, &st));*/
		if (stat(path, &st) == 0)
		{
			valid_stat = 1, free(*function), *function = NULL;
			*function = strdup(path);
			if (!function)
			{
				printf("Error realloc\n");
				break;
			}
			break;
		}
			for (k = 0; k < strlen(path); k++)
			path[k] = 0;
	}
	array_in_free(array_dir);
	return (valid_stat);
}
