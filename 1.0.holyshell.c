/*
* File: holyshell.c
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

/*struct termios original_termios;
void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}*/

/**
 * main - simple_shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL, **array_str = NULL;
	size_t bufsiz = 0;
	int err, buf_st, cmd_count;


	/*tcgetattr(STDIN_FILENO, &original_termios);
    atexit(restore_terminal);*/
	signal(SIGINT, sigint_handler);

	while (1)
	{
		printf("%s%s%s%s%s#holy$hel%s ", INVRT, BOLD, BLINK, YELLOW, BG_CYAN, RESET);

		err = getline(&buffer, &bufsiz, stdin);
		if (err == -1)
		{
			free(buffer);
			break;
		}

		buf_st = buff_cleaner(buffer);
		if (buf_st < 0)
		{
			free(buffer), buffer = NULL;
			continue;
		}
		cmd_count = split_str2(&array_str, buffer, " ");

		if (spc_cmd(array_str[0], cmd_count))
			array_in_free(array_str), free(buffer), buffer = NULL, exit(1);

		if (get_dir(&array_str[0]) == 1)
			children_maker(array_str[0], array_str);
		else
			perror("Error");

		array_in_free(array_str), free(buffer), buffer = NULL;
	}
	return (0);
}
