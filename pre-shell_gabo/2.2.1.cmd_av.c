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
	char **arr = NULL, *token, *buffer_cp;
	int words = 0, i = 0;
	//int j,  
	int buf_len = 0;
	//, flag = 0;

	if (!str)
		return (arr);	

	buffer_cp = strdup(str);
	buf_len = strlen(buffer_cp);

	if (buffer_cp[buf_len - 1] == '\n')
		buffer_cp[buf_len - 1] = '\0';

	token = strtok(str, " ");
	while (token)
	{
		words++;
		printf("token = %s\n", token);
		token = strtok(NULL, " ");
	}
	
	printf("words = %d\n", words);

	arr = malloc(words + 1 * sizeof(char *));

	token = strtok(buffer_cp, " ");
	while (i < words)
	{
		arr[i] = strdup(token);
		printf("arr[%d] = %s\n", i, arr[i]);
		token = strtok(NULL, " ");
		i++;
	}
	
	arr[words] = NULL;

	i = 0;
	while (i < words + 1)
	{
		printf("arr[%d] = %s\n", i, arr[i]);
		i++;
	}
	



	return (arr);
	
}


/**
 * main - splits a string pased by cmd
 * Return: 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;  /*,  *token; */
	size_t bufsiz = 0;
	int err;

	char **p;
	int i;

	while (1)
	{
		printf("$ ");
		err = getline(&buffer, &bufsiz, stdin);

		if (err == -1)
		{
			printf("Error reading command.\n");
			break;
		}

		if (strncmp(buffer, "exit\n", 5) == 0)
			break;

		printf("cmd = %s", buffer);
/*
		token = strtok(buffer, " ");
		while (token)
		{
			printf("\"array\" = %s", token);
			token = strtok(NULL, " ");
		}
*/
		p = cmd_line_to_av(buffer);
		i = 0;
		while (p[i])
		{
			printf("array[%d] = %s\n", i, p[i]);
			i++;
		}
		i = 0;
		while (p[i])
		{
			printf("libero array[%d] = %s\n", i, p[i]);
			free(p[i]);
			i++;
		}

		printf("libero p\n");
		free(p);
	}

	printf("libero buffer\n");
	free(buffer);

	return (0);
}
