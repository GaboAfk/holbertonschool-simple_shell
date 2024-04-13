#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork, wait & execve
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status, i;
	char *argv[] = {"ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			printf("Hijo %d ejecutando\n", i + 1);
			if (execve("/bin/ls", argv, NULL) == -1)/*ruta de ls*/
				perror("Error:");
		}
		else
		{
			wait(&status);
			printf("Hijo %d terminó ejecución\n", i + 1);
		}
	}
	return (0);
}

















