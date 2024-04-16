#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 */

extern char **environ;

void print_path(void)
{
	int comp, c = 0;
	char *token, *pat;
	unsigned int cont;

	for (cont = 0; environ[cont] != NULL; cont++)
	{
		comp = strncmp("PATH", environ[cont], strlen("PATH"));

		if (comp == 0)
		{
			pat = malloc(strlen(environ[cont] + 1));
			if (!pat)
				return;
			strcpy(pat, environ[cont]);

			token = strtok(pat, ":");
			c++;

			while (token)
			{
				printf("Directory %i: %s\n", c, token);
				token = strtok(NULL, ":");
				c++;
			}
		}
	}
	free(pat);
	return;

}

int main(void)
{
	char *line = NULL;
	size_t len = 0, lenline = 0;
	ssize_t input;

	while (1)
	{
		printf("$ ");
		
		input = getline(&line, &len, stdin);
		if (input == -1)
		{
			perror("Error");
		}
		
		lenline = strlen(line);
		
		if (line && line[lenline - 1] == '\n')
			line[lenline - 1] = '\0';

		if (strncmp(line, "printpath", 9) == 0)
				print_path();

		if (strncmp(line, "exit", 4) == 0)
			exit(1);
        }

	return (0);
}
