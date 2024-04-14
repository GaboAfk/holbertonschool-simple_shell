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
	int words = 0, i = 0, buf_len;
	int j;

	if (!str)
		return (arr);

	buffer_cp = strdup(str);
	buf_len = strlen(buffer_cp);

	if (!buffer_cp)
		return (NULL);

	if (buffer_cp[buf_len - 1] == '\n')
		buffer_cp[buf_len - 1] = '\0';

	printf("buffer_cp = %s\n", buffer_cp);
	
	token = strtok(buffer_cp, " ");
	while (token)
	{
		words++;
		token = strtok(NULL, " ");
	}

	printf("total words = %d\n", words);

	buffer_cp = strdup(str);
	if (!buffer_cp)
		return (NULL);

	if (buffer_cp[buf_len - 1] == '\n')
		buffer_cp[buf_len - 1] = '\0';

	printf("malloc(%d + %d * %ld);\n", words, 1, sizeof(char *));
	arr = malloc(words + 1 * sizeof(char *));
	if (!arr)
	{
		free(buffer_cp);
		return (NULL);
	}
printf("buffer_cp = %s\n", buffer_cp);
	token = strtok(buffer_cp, " ");
	while (token)
	{
		
	printf("token = %s\n", token);
		arr[i] = strdup(token);
	
	printf("arr[%d] = %s\n", i, arr[i]);
		if (!arr[i])
		{
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			free(buffer_cp);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " ");
	}
	printf("i = %d\n", i);
	/*if (i > 0)
		arr[i + 1] = NULL;
	else
		arr[i] = NULL;*/
	free(buffer_cp);


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
			free(p[i]);
			i++;
		}
		free(p);
	}

	free(buffer);

	return (0);
}
