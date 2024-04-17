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

	printf("name = %s name_len = %ld\n", name, name_len);

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

	printf("entre en get_dir y function = %s\n", *function);

	if (stat(*function, &st) == 0)
		return;

	printf("function invalida busco en PATH\n");

	directories = _getenv("PATH");

	array_dir = split_str(directories, ":");

	while (array_dir && array_dir[i])
	{
		printf("array_dir[%d] = %s\n", i, array_dir[i]);
		i++;
	}

	i = 0;
	while (array_dir && array_dir[i])
	{
		memset(path, '\0', sizeof(path));

		strcat(path, array_dir[i]);
		strcat(path, "/");
		strcat(path, *function);

		printf("path = %s\n", path);

		if (stat(path, &st) == 0)
		{
			printf("stat(%s, &st) == 0\n", path);
			printf("sizeof%s = %ld\n", *function, sizeof(*function));
			function = realloc(function, (strlen(path) + 1) * sizeof(char));
			if (!function)
			{
				printf("Error realloc\n");
				break;
			}
			printf("sizeof%s = %ld\n", *function, sizeof(*function));

			strcpy(*function, path);
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
