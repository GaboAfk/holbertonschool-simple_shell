/*
* File: patheneitor.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/
#include "zzz.h"
/**
 * split_str2 - split an str
 * @buffer: entry string
 * Return: an array of each words of str
 */
int split_str2(char ***array, char *buffer, char *delim)
{
	char *token, *cp_buffer;
	int words = 0, i = 0;

	if (!buffer)
		return (0);

	cp_buffer = strdup(buffer);
	if (!cp_buffer)
		return (0);

	token = strtok(buffer, delim);

	while (token)
		words++, token = strtok(NULL, delim);

	*array = malloc((words + 1)  * sizeof(char *));
	if (!array)
	{
		free(cp_buffer);
		return (0);
	}

	token = strtok(cp_buffer, delim);
	while (token)
	{
		(*array)[i] = strdup(token);
		if (!(*array)[i])
		{
			array_in_free(*array), free(cp_buffer);
			return (0);
		}
		token = strtok(NULL, delim);
		i++;
	}

	(*array)[words] = NULL, free(cp_buffer);
	return (i);
}

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

int general_function(char **array_multi, char *multi_i, char *delim)
{
	int cmd_count, spc_val;
	char **array_str = NULL;

			cmd_count = split_str2(&array_str, multi_i, delim);

			spc_val = spc_cmd(array_str, cmd_count);
			if (spc_val == 1)
				//free(multi_i), multi_i = NULL, 
				array_in_free(array_multi), exit(array_in_free(array_str));
			else if (spc_val > 1)
			{
				//free(buffer), buffer = NULL, array_in_free(array_str);
				return (1);
			}

			if (get_dir(&array_str[0]) == 1)
				children_maker(array_str[0], array_str);
			else
				perror("Error");
			array_in_free(array_str);
			//free(buffer), buffer = NULL;
		
		return (0);
}