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
	int i = 0, k, valid_stat = 0;
	struct stat st;

	if (stat(*function, &st) == 0)
		return (1);

/*	if (strncmp(*function, "env", 3) == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return;
	}
*/

//	printf("-----------------\n");
//	printf("get_dir(function)\n");
//	printf("-----------------\n");
//	printf("function = %s\n", *function);

	directories = _getenv("PATH");


//	printf("directories = %s\n", directories);

	split_str2(&array_dir, directories, ":");

	free(directories);

	i = 0;
	while (array_dir && array_dir[i])
	{
//		printf("array_dir[%d] = %s\n", i, array_dir[i]);
		i++;
	}

	i = 0;
	while (array_dir && array_dir[i])
	{
	//	memset(path, 0, sizeof(path));
		for (k = 0; k < 1024; k++)
			path[k] = 0;

		strcat(path, array_dir[i]);
		strcat(path, "/");
		strcat(path, *function);

		if (stat(path, &st) == 0)
		{
			valid_stat = 1;
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
//	printf("--------------------------\n");
//	printf("salgo de get_dir(function)\n");
//	printf("--------------------------\n");

 return (valid_stat);

}
