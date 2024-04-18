/*
* File: holyshell.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/

#include "zzz.h"

/**
 * main - simple_shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsiz = 0, buf_len;
	int err, status;
	pid_t pid;
	char *argv[] = {NULL, NULL};

	while (1)
	{
		printf("#holy$hel ");

		err = getline(&buffer, &bufsiz, stdin);

		if (err == -1)
		{
			printf("Error invalid command\n");
			exit(1);
		}

		buf_len = strlen(buffer);
		if (buffer[buf_len - 1] == '\n')
			buffer[buf_len - 1] = '\0';

		if (strncmp(buffer, "exit", 4) == 0 || strncmp(buffer, "EOF", 3) == 0)
			break;

		argv[0] = buffer;

		pid = fork();

		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (pid == 0)
		{
		if (execve(argv[0], argv, environ) == -1)
			perror("Error");
		break;
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0);
}
