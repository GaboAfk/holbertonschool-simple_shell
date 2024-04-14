#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *
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
	{
		printf("error, no se ingreso datos");
		return (-1);
	}

	if (execve("/bin/ls", line, NULL) == -1)
	      return (-1);

	free (line);
	return (0);


}
