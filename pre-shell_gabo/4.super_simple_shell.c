/*
* File: 4.super_simple_shell.c
* Auth: Gabriel Morffe
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

	buffer_cp = strdup(str);
	if (!buffer_cp)
		return (NULL);

	token = strtok(str, " ");
	while (token)
	{
		words++;
		token = strtok(NULL, " ");
	}

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
		token = strtok(NULL, " ");
		i++;
	}
	
	arr[words] = NULL;
	free(buffer_cp);
	return (arr);
}


/**
 * main - first version of a super simple shell that can run commands with their full path, without any argument.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL, **array = NULL;
	size_t buf_siz = 0;
	ssize_t err;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("hiper$$hel ");
		err = getline(&buffer, &buf_siz, stdin);
		if (err == -1)
		{
			printf("reading input error\n");
			break;
		}

		if (strncmp(buffer, "exit\n", 5) == 0)
		{
			free(buffer);
			break;
		}

		buffer[strlen(buffer) - 1] = '\0';
		array = cmd_line_to_av(buffer);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		
		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
			wait(&status);
	}
	return (0);
}
