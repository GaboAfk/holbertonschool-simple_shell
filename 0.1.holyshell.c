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
	size_t bufsiz = 0;
	int err;
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

		if (buffer[bufsiz - 1] == '\n')
			buffer[bufsiz - 1] = '\0';

		if (strncmp(buffer, "exit", 4) == 0 || strncmp(buffer, "EOF", 3) == 0)
			break;

		argv[0] = buffer;

		if (execve(argv[0], argv, environ) == -1)
			perror("Error");
	}
	free(buffer);
	return (0);
}
