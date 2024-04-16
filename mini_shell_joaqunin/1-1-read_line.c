#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 *
 */


int main (void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");

	read = getline(&line, &len, stdin);

	if (read == -1)
		printf("Error al leer el comando");
	else
	printf("%s", line);

	free(line);
	return(0);
}
