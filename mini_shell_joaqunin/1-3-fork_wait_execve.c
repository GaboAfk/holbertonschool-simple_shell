#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 *
 *
 */

int main (void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int cont, status;
	pid_t pid;

	for (cont = 0; cont < 5; cont++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error:");

			return (0);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);


}
