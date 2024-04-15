#include <stdio.h>
#include <stdlib.h>

/**
 *
 */

int main (void)
{
	extern char **environ;
	unsigned int cont;

	for (cont = 0; environ[cont] != NULL; cont++)
		printf("%s\n", environ[cont]);

	return (0);
}
