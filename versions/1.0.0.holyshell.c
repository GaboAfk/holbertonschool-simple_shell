/*
* File: holyshell.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/

#include "zzz.h"

/**
 * split_str - split an str
 * @buffer: entry string
 * Return: an array of each words of str
 */
char **split_str(char *buffer, char *delim)
{
	char *token, *cp_buffer, **array;
	int words = 0, i = 0, j;

	if (!buffer)
		return (NULL);
	cp_buffer = strdup(buffer);
	if (!cp_buffer)
		return (NULL);
	token = strtok(buffer, delim);
	while (token)
	{
		words++;
		token = strtok(NULL, delim);
	}
	array = malloc((words + 1)  * sizeof(char *));
	if (!array)
	{
		free(cp_buffer);
		return (NULL);
	}
	token = strtok(cp_buffer, delim);
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
		token = strtok(NULL, delim);
		i++;
	}
	array[words] = NULL;
	free(cp_buffer);
	return (array);
}

/**
 * sigint_handler - rompenachos
 * @signum: signum
 */
void sigint_handler(int signum)
{
	(void)signum;
	printf("No tan rapido amigo GGizi\n");
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
	int err, i = 0, buf_st;
	//int status, valid;
	//struct stat st;
	//pid_t pid;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		printf("%s%s%s%s%s#holy$hell%s ", INVERT, BOLD, BLINK, YELLOW, BG_CYAN, RESET);

		err = getline(&buffer, &bufsiz, stdin);

		if (err == -1)
		{
			printf("EOF break\n");
			free(buffer);
			break;
		}

	//	printf("pre-buffer = %s\n", buffer);

		buf_st = buff_cleaner(buffer);
		if (buf_st < 0)
		{
			free(buffer);
			exit(buf_st);
		}
		else if (buf_st > 0)
		{
			free(buffer);
			continue;
		}

	//	printf("buffer = %s\n", buffer);
		array_str = split_str(buffer, " ");
		//array_str = malloc(2 * sizeof(char *));
		//array_str[0] = strdup(buffer);
		//array_str[1] = NULL;

	/*	if (extra_cmd(array_str[0]) == 1)
		{
			for (i = 0; array_str[i] && i < 3; i++)
			{}
			i < 2 ? break : void;
		}
*/
		printf("array_str[%d] = %s\n", 0, array_str[0]);
		if (get_dir(&array_str[0]) == 1)
		{
			for (i = 0; array_str && array_str[i]; i++)
				printf("array_str[%d] = %s\n", i, array_str[i]);

			children_maker(array_str[0], array_str);
		}
		else
			perror("Error");

		//printf("array_str[0] = %s\n", array_str[0]);
		//printf("array_str[1] = %s\n", array_str[1]);
	/*	valid = stat(array_str[0], &st);
		if (valid == 0)
		{
			pid = fork();

			if (pid == -1)
			{
				perror("Error");
				return (1);
			}

			if (pid == 0)
			{
				if (execve(array_str[0], array_str, environ) == -1)
					perror("Error");
			}
			else
				wait(&status);
		}
		else
			perror("Error");
*/
		array_in_free(array_str);
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
