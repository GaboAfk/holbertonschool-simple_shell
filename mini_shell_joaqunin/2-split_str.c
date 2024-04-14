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
	int cont = 0;

	cp_line = malloc(strlen(line) + 1);
	if (!cp_line)
		return (NULL);

	strcpy(cp_line, line);

	token = strtok(line, " ");
	cont++;

	while (token)
	{
		token = strtok(NULL, " ");
		cont++;
	}

	array_str = malloc(cont * sizeof(char*));
	if (!array_str)
		return (NULL);

	token = strtok(cp_line, " ");
	cont = 0;

	while (token)
	{
		array_str[cont] = malloc(strlen(token) + 1);
		if (array_str[cont] == NULL)
			return (NULL);
		strcpy(array_str[cont], token);
		token = strtok(NULL, " ");
		cont++;
	}

	free(cp_line);
	return (array_str);

}

int main (void)
{
	char *line = NULL;
	char **array;
	size_t len = 0;
	ssize_t impu;
	int c = 0;

	printf("$ ");

	impu = getline(&line, &len, stdin);

	if (impu == -1)
	{
		printf("Error, no data entered");
		return (-1);
	}
	else
	{
		array = split_str(line);
	}

	while (array)
	{
		printf("%s\n", array[c]);
		c++;
	}

	while (c > 0)
	{
		free(array[c]);
		c--;
	}

	free (array);

	return (0);
}
