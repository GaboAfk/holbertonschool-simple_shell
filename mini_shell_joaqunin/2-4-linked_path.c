#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 *
 */

struct path_list
{
	char *name;
	struct path_list *next;
};

typedef struct path_list pat_list;

extern char **environ;

pat_list *add_node_end (pat_list **head, char *str)
{
	pat_list *new_node;

	new_node = malloc(sizeof(pat_list));
	if (!new_node)
		return (NULL);

	new_node->name = strdup(str);
	if (!new_node->name)
	{
		free(new_node);
		return (NULL);
	}
	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}
	else
	{
		while ((*head)->next != NULL)
			head = &(*head)->next;
		(*head)->next = new_node;
	}

	return (new_node);

}

pat_list *linked_path(void)
{
	int comp, c = 0;
	char *token, *pat;
	unsigned int cont;

	pat_list *pat_head = NULL;

	for (cont = 0; environ[cont] != NULL; cont++)
	{
		comp = strncmp("PATH", environ[cont], strlen("PATH"));

		if (comp == 0)
		{
			pat = malloc(strlen(&((environ[cont])[strlen("PATH=")])) + 1);
			if (!pat)
				return (NULL);
			strcpy(pat, &((environ[cont])[strlen("PATH=")]));

			token = strtok(pat, ":");
			c++;

			while (token)
			{
				printf("Token %i :%s\n", c, token);
				add_node_end(&pat_head, token);
				token = strtok(NULL, ":");
				c++;
			}
		}
	}
	free(pat);
	return (pat_head);

}

int main(void)
{
	int contpath;
	pat_list *head, *aux;

	head = linked_path();
	aux = head;

	for (contpath = 0; head; contpath++)
	{
		printf("Direccion %i : %s\n", contpath, head->name);
		head = head->next;
	}

	head = aux;
	while (head)
	{
		aux = head->next;
		free(head->name);
		free(head);
		head = aux;
	}

	return (0);
}
