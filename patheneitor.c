/*
* File: patheneitor.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/

#include "zzz.h"

/**
 * stat - check the status of the path
 * @path: entry string
 * @st: entry struct
 * Return: 0 if exist -1 if dont
 */
int stat(char *path, struct stat st)
{
	if (stat(path, &st) == 0)
	{
		printf("FOUND %s\n", path);
	}
	else
	{
		printf("NOT FOUND %s\n", path);
		return (-1)
	}

	return (0)
}

/**
 * _getenv - search path in environ
 * @name: PATH to find
 * Return: PATH of @name of NULL
 */
char *_getenv(char *name)
{	
	int i = 0;
	size_t name_len = strlen(name);

	while (environ[i])
	{
		if (strncmp(name, environ[i], name_len) && (environ[i])[name_len] == '=')
			return (&((environ[i])[name_len + 1]));
		i++;
	}
	return (NULL);
}

/**
 * _getenv - search path in environ
 * @directories: entry str of directories
 * Return: PATH of @name of NULL
 */
char *_getenv(char *directories)
{	
}
