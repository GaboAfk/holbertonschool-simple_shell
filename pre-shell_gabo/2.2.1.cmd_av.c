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
	char **arr = NULL, *token = NULL, *buffer_cp = NULL;
	int words = 0, i = 0, j = 0;  

	if (!str)
		return (NULL);	

	printf("------------------\n");
	printf("entré en cmd_to_av\n");
	printf("------------------\n");

	buffer_cp = strdup(str);
	if (!buffer_cp)
		return (NULL);
	
	token = strtok(str, " ");
	while (token)
	{
		words++;
		printf("token = %s\n", token);
		token = strtok(NULL, " ");
	}
	
	printf("words = %d\n", words);

	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
	{
		free(buffer_cp);
		return (NULL);
	}
	
	token = strtok(buffer_cp, " ");
	while (token)
	{
		arr[i] = strdup(token);
		if (!arr[i])
		{
			for (j = 0; j < i; j++)
			{
				free(arr[j]), free(arr), free(buffer_cp);
				printf("ERROR COPY INTO AV\n");
				return (NULL);
			}
		}
		printf("arr[%d] = %s\n", i, arr[i]);
		token = strtok(NULL, " ");
		i++;
	}

	arr[words] = NULL;
	printf("arr[%d] = %s\n", i, arr[i]);

	free(buffer_cp);

	printf("------------------\n");
	printf("salgo de cmd_to_av\n");
	printf("------------------\n");

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
	int buf_len = 0;
	ssize_t err = 0;

	char **p = NULL;
	int i = 0;

	while (1)
	{
		printf("$ ");
		err = getline(&buffer, &bufsiz, stdin);
		
		if (err == -1)
		{
			printf("Error reading command.\n");
			return (-1);
		}

		if (strncmp(buffer, "exit\n", 5) == 0)
		{
			free(buffer);
			break;
		}

		buf_len = strlen(buffer);
		if (buffer[buf_len - 1] == '\n')
		buffer[buf_len - 1] = '\0';

		printf("cmd = %s\n", buffer);

		p = cmd_line_to_av(buffer);
		i = 0;
		
		printf("--------------\n");
		printf("imprimir array\n");
		printf("--------------\n");

		while (p[i])
		{
			printf("array[%d] = %s\n", i, p[i]);
			i++;
		}
		
		printf("-------------\n");
		printf("liberar array\n");
		printf("-------------\n");

		while (i >= 0)
		{
			printf("libero array[%d] = %s\n", i, p[i]);
			free(p[i]);
			i--;
		}

		printf("libero p\n");
		free(p);
		p = NULL;
		
		printf("libero buffer\n");
		free(buffer);
		buffer = NULL;
	}

	return (0);
}
