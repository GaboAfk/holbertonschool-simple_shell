/*
* File: 2.2.command_line_to_av.c
* Auth: Gabriel Morffe
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * cmd_line_to_av - function that splits a string
 * @str: string to split.
 * Return: returns an array of each word of the string.
 */
char **cmd_line_to_av(char *str)
{
	char **arr = NULL;
	char *token, *buffer_cp;
	int words = 0, i = 0;

	if (!str)
		return (arr);

	buffer_cp = strdup(str);
	if (!buffer_cp)
		return (NULL);

	token = strtok(buffer_cp, " ");
	while (token)
	{
		words++;
		token = strtok(NULL, " ");
	}

	arr = malloc(sizeof(words * sizeof(char *)));
	if (!arr)
		return (NULL);

	token = strtok(buffer_cp, " ");
	while (token)
	{
		arr[i] = strdup(token);
		if (!arr[i])
			return (NULL);
		i++;
		token = strtok(NULL, " ");
	}
	free(buffer_cp);
	return (arr);
}


/**
 * main - splits a string pased by cmd
 * Return: 0 (Success)
 */
int main(void)
{
	char *buffer = NULL, *token;
	size_t bufsiz = 0;
	int err;

/*	char **p;*/
/*	int i;*/

	while (1)
	{
		printf("$ ");
		err = getline(&buffer, &bufsiz, stdin);

		if (err == -1)
		{
			printf("Error reading command.\n");
			break;
		}

		if (strcmp(buffer, "exit\n") == 0)
			break;

		printf("cmd = %s", buffer);

		token = strtok(buffer, " ");
		while (token)
		{
			printf("\"array\" = %s", token);
			token = strtok(NULL, " ");
		}

/*		p = cmd_line_to_av(buffer);*/
/*		i = 0;*/
/*		while (p[i])*/
/*		{*/
/*			printf("array[%d] = %s\n", i, p[i]);*/
/*			i++;*/
/*		}*/
	}
/*	i = 0;*/
/*	while (p[i])*/
/*	{*/
/*		free(p[i]);*/
/*		i++;*/
/*	}*/
/*	free(p);*/
	free(buffer);

	return (0);
}
