#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 */	

extern char **environ;

char *_getenv(const char *input_var)
{
	int comp;
	unsigned int cont;

	for (cont = 0; environ[cont] != NULL; cont ++)
	{
		comp = strncmp(input_var, environ[cont], strlen(input_var));

		if (comp == 0)
			return (&((environ[cont])[strlen(input_var) + 1]));
	}

	return (NULL);




}

int main (void)
{
	char *line = NULL, *env_var = NULL;
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

		if (strncmp(line, "exit", 4) == 0)
			exit(1);

		env_var = _getenv(line);

		if (env_var)
			printf("Variable : %s\n", env_var);
	}
	return (0);
}

