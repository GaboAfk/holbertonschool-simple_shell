#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char **split_str (char *line);

/**
 *
 */

int main (void)
{
	char *line = NULL;
	char **array;
	size_t len = 0, lenline = 0;
	ssize_t input;
	int c = 0, status;
	pid_t pid;

	while (1)
	{
		printf("$ ");

		input = getline(&line, &len, stdin);

		lenline = strlen(line);

		if (line && line[lenline - 1] == '\n')
			line[lenline - 1] = '\0';

		if (input == -1)
		{

		}
		else
		{
			array = split_str(line);
		}

		pid = fork();

		if (pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
			{
				perror("Error");
				return (1);
			}
			for (; c >= 0; c++)
				free(array[c]);
			free(line);
			free(array);

		}
		else
			wait(&status);
	}

	return (0);
}
