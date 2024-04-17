/*
* File: holyshell.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/

#include "zzz.h"

#define BOLD "\033[1m"
#define BLINK "\033[6m"
#define INVERT "\033[7m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BG_CYAN "\033[46m"

/**
 * split_str - split an str
 * @buffer: entry string
 * Return: an array of each words of str
 */
char **split_str(char *buffer)
{
	char *token, *cp_buffer;
	char **array;
	int words = 0, i = 0, j;

	if (!buffer)
		return (NULL);

	cp_buffer = strdup(buffer);
	if (!cp_buffer)
		return (NULL);

	token = strtok(buffer, " ");

	while (token)
	{
		words++;
		token = strtok(NULL, " ");
	}

	array = malloc((words + 1)  * sizeof(char *));
	printf("array = malloc((%d + 1) * %ld)\n", words, sizeof(char *));
	if (!array)
	{
		free(cp_buffer);
		return (NULL);
	}

	token = strtok(cp_buffer, " ");

	while (token)
	{
		array[i] = strdup(token);
		if (!array[i])
		{
			for (j = 0; j < i; j++)
				free(array[j]);

			free(array);
			free(cp_buffer);
			printf("Error copy into array\n");
			return (NULL);
		}

		token = strtok(NULL, " ");
		i++;
	}

	array[words] = NULL;
	free(cp_buffer);
	return (array);
}

/**
 * main - simple_shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;
	char **array_str = NULL;
	size_t bufsiz = 0;
	int err, i = 0, buf_len;

	while (1)
	{
		printf("%s%s%s%s%s#holy$hel%s ", INVERT, BOLD, BLINK, YELLOW, BG_CYAN, RESET);

		err = getline(&buffer, &bufsiz, stdin);

		if (err == -1)
		{
			printf("Error invalid command\n");
			return (-1);
		}

		buf_len = strlen(buffer);
		if (buffer[buf_len - 1] == '\n')
			buffer[buf_len - 1] = '\0';

		if (strncmp(buffer, "exit", 4) == 0 || strncmp(buffer, "EOF", 3) == 0)
		{
			free(buffer);
			break;
		}

		array_str = split_str(buffer);

		if (execve(array_str[0], array_str, environ) == -1)
			perror("Error");

		i = 0;
		while (array_str && array_str[i])
		{
			printf("array_str[%d] = %s\n", i, array_str[i]);
			i++;
		}
		printf("array_str[%d] = %s\n", i, array_str[i]);
		i = 0;
		while (array_str && array_str[i])
		{
			printf("free(array_str[%d] = %s)\n", i, array_str[i]);
			free(array_str[i]);
			i++;
		}
		printf("free(array_str[%d] = %s)\n", i, array_str[i]);
		free(array_str[i]);

		if (array_str)
		free(array_str);
		array_str = NULL;

		free(buffer);
		buffer = NULL;
	}
	return (0);
}
