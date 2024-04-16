/*
* File: 6.5._setenv.c
* Auth: Gabriel Morffe
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define RED "\033[31m"
#define RESET "\033[0m"
#define BG_CYAN "\033[46m"

/**
 * _setenv - changes or adds an environment variable (without using setenv).
 * @name: variable name
 * @value: variable value
 * @overwrite: overwrite option.
 * @env: pointer to enviroment variables string.
 * Return: 0 (Success). -1 (Failure).
 */
int _setenv(const char *name, const char *value, int overwrite, char **env)
{
	char *var = NULL;
	int i = 0, j = 0, name_len, value_len;

	if (!name || !value || !env)
		return (-1);

	name_len = strlen(name);
	value_len = strlen(value);

	var = malloc((name_len + value_len + 2) * sizeof(char));

	printf("\033[5m%s%sname = %s value = %s overwrite = %d%s\n", RED, BG_CYAN, name, value, overwrite, RESET);

	printf("imprimi prototype\n");
	if (var == NULL)
		return (-1);

	printf("var = %s\n", var);

	while (name[i])
	{
		var[i] = name[i];
		i++;
	}
	var[i] = '=';
	i++;

	while (value[j])
	{
		var[i] = value[j];
		i++;
		j++;
	}
	var[i] = '\0';

	printf("var = %s\n", var);

	i = 0;
	while (env[i])
		i++;

	printf("env tiene %d elementos\n", i);

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], name, strlen(name)) == 0)
		{
			break;
		}
		i++;
	}

	if (env[i])
		printf("env[%d] = %s\n", i, env[i]);
	else
		printf("No existe %s en env\n", name);

	if (env[i]) /*existe name*/
	{
		if (overwrite != 0) /* si existe lo modifico*/
		{
			env[i] = realloc(env[i], strlen(var));
			if (!env[i])
				return (-1);
			env[i] = strdup(var);
			if (!env[i])
				return (-1);
			printf("existe %s, lo modifico\n", name);
		}
		else
		{
			printf("existe %s NO modifico\n", name);
			return (0);
		}
	}
	else/*no existe, lo agrego al final*/
	{
		env = realloc(env, (i + 2) * sizeof(char *));
		if (!env)
			return (-1);
		env[i] = strdup(var);
		env[i + 1] = NULL;
		printf("NO existe %s, lo agrego al final\n", name);
	}

	free(var);

	return (0);
}


/**
 * main - use _setenv
 * Return: 0 (Success). -1 (Failure).
 */
extern char **environ;
int main(void)
{
	char **env;
	int res, i = 0, j = 0;
	char *name = "NEWPATH", *value = "/GG/izi";

	while (environ[i])
		i++;

	printf("environ tiene %d strings\n", i);

	env = malloc((i + 1) * sizeof(char *));
	printf("env le asigno ((%d + 1) * %ld) de memoria\n", i, sizeof(char *));

	while (j < i)
	{
		printf("environ[%d] = %s\n", j, environ[j]);
		env[j] = strdup(environ[j]);
		if (!env[j])
			return (-1);
		j++;
	}
	env[j] = NULL;

	printf("--------------\n");
	printf("BEFORE _SETENV\n");
	printf("--------------\n");

	j = 0;
	while (j < i && env[j])
	{
		printf("env[%d] = %s\n", j, env[j]);
		j++;
	}

	printf("--------------\n");
	printf("LLAMO _SETENV\n");
	printf("--------------\n");


	res = _setenv(name, value, 0, env);

	printf("--------------\n");
	printf("AFTER _SETENV\n");
	printf("--------------\n");

	j = 0;
	while (env[j])
	{
		printf("env[%d] = %s\n", j, env[j]);
		j++;
	}

	printf("----------\n");
	printf("LIBERO ENV\n");
	printf("----------\n");

	j = 0;
	while (env[j] && j < i)
	{
		free(env[j]);
		j++;
	}
	free(env);

	return (res);
}
