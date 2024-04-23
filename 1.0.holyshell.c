/*
* File: holyshell.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/

#include "zzz.h"

/**
 * split_str2 - split an str
 * @array: enters and modifies an a array of strings
 * @buffer: entry buffer or input prompt
 * @delim: entry delimiter
 * Return: n°of commands and flags
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
 * main - simple_shell
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *buffer = NULL, **array_str = NULL;
	size_t bufsiz = 0;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s%s%s%s%s#holy$hell%s ", INV, BOLD, BLINK, YELLOW, BG_CYAN, RESET);

		if (getline(&buffer, &bufsiz, stdin) == -1)
		{
			free(buffer);
			break;
		}

		if (buff_cleaner(buffer) < 0)
		{
			free(buffer), buffer = NULL;
			continue;
		}

		if (spc_cmd(array_str[0], split_str2(&array_str, buffer, " ")))
			array_in_free(array_str), free(buffer), buffer = NULL, exit(1);

		if (get_dir(&array_str[0]) == 1)
			children_maker(array_str[0], array_str);
		else
			perror("Error");

		array_in_free(array_str), free(buffer), buffer = NULL;
	}
	return (0);
}
