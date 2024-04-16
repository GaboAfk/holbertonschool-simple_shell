/*
* File: 6.4.path_linked_list.c
* Auth: Gabriel Morffe
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

/**
 * _getenv - search PATH @name in environ
 * @name: PATH to find.
 * Return: PATH of @name or NULL.
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t name_length = strlen(name);
	char **env = environ;

	while (env[i])
	{
		if (strncmp(env[i], name, name_length) == 0
				&& (env[i])[name_length] == '=')
			return (&((env[i])[name_length + 1]));
		i++;
	}
	return (NULL);
}
/**
 * struct node - directory node.
 * @directory: name of directory.
 * @next: pointer to the next node..
 */
typedef struct node
{
	char *directory;
	struct node *next;
} node;

/**
 * path_linked_list_builder - builds a linked list of the PATH directories.
 * @name: path to built.
 * Return: linked list of directories in @name.
 */
node *path_linked_list_builder(char *name)
{
	char *token, *path = _getenv(name);
	node *head = NULL, *list = NULL, *aux;

	if (!path)
		return (NULL);
	token = strtok(path, ":");
	while (token)
	{
		aux = head;

		list = malloc(sizeof(node));
		if (!list)
			return (NULL);
		list->directory = NULL;
		list->next = NULL;

		while (aux && aux->next)
			aux = aux->next;
		if (aux)
			aux->next = list;
		if (!head)
			head = list;
		list->directory = strdup(token);
		if (!list->directory)
		{
			free(list);
			list = NULL;
			while (!head)
			{
				free(head->directory);
				list = head;
				head = head->next;
				free(list);
			}
		}
		list = list->next;
		token = strtok(NULL, ":");
	}
	return (head);
}

/**
 * main - prints each directory contained in the
 * the environment variable PATH, one directory per line.
 *
 * Return: Always 0 (Success). 1 (Failure).
 */
int main(void)
{
	node *list, *aux;

	list = path_linked_list_builder("PATH");

	printf("-----------\n");
	printf("linked list\n");
	printf("-----------\n");

	while (list)
	{
		printf("%s\n", list->directory);
		aux = list;
		list = list->next;
		free(aux->directory);
		free(aux);
		aux = NULL;
	}

	return (0);
}
