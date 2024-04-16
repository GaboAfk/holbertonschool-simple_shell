/*
* File: 6.3.path_printer.c
* Auth: Gabriel Morffe
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

/**
 * _getenv - search PATH @name in environ
 * @name: PATH to find.
 * Return: PATH of @name or NULL.
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t name_length = strlen(name);
	char **env = environ;

	while (env[i])
	{
		if (strncmp(env[i], name, name_length) == 0
				&& (env[i])[name_length] == '=')
			return (&((env[i])[name_length + 1]));
		i++;
	}
	return (NULL);
}

/**
 * path_printer - prints each directory contained in the the
 *		environment variable PATH, one directory per line.
 * @name: path to split..
 */
void path_printer(char *name)
{
	char *token, *path = _getenv(name);

	if (!path)
		return;

	token = strtok(path, ":");
	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}

/**
 * main - prints each directory contained in the
 * the environment variable PATH, one directory per line.
 *
 * Return: Always 0 (Success). 1 (Failure).
 */
int main(void)
{
	path_printer("PATH");

	return (0);
}
