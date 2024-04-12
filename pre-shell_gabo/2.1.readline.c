/*
* File: 2.1.readline.c
* Auth: Gabriel Morffe
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - program that prints "$ ", wait for the user to enter a command and
 *			prints it on the next line.
 * Return: 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsiz = 0;
	int err;

	while (1)
	{
		printf("$ ");
		err = getline(&buffer, &bufsiz, stdin);

		if (err == -1)
		{
			printf("Error reading command.\n");
			break;
		}

		if (strcmp(buffer, "exit\n") == 0)
			break;

		printf("%s", buffer);
	}

	free(buffer);

	return (0);
}
