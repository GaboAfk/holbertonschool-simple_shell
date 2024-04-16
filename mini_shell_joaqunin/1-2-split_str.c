#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 */

char **split_str (char *line)
{
	char *token, *cp_line = NULL;
	char **array_str;
	char delim[] = {" "};
	int cont = 0;

	cp_line = malloc(strlen(line) + 1);
	if (!cp_line)
		return (NULL);

	strcpy(cp_line, line);

	token = strtok(line, delim);
	cont++;

	while (token)
	{
		token = strtok(NULL, delim);
		cont++;
	}

	array_str = malloc(cont * sizeof(char*));
	if (!array_str)
		return (NULL);

	token = strtok(cp_line, delim);
	cont = 0;

	while (token)
	{
		array_str[cont] = malloc(strlen(token) + 1);
		if (array_str[cont] == NULL)
			return (NULL);
		strcpy(array_str[cont], token);
		token = strtok(NULL, delim);
		cont++;
	}

	free(cp_line);
	return (array_str);

}
