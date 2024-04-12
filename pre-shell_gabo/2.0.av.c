/*
* File: 2.0.av
* Auth: Gabriel Morffe
*/
#include <stdio.h>

/**
 * main - prints all the arguments, without using ac.
 * @ac: is the number of items in @av.
 * @av: is a NULL terminated array of strings.
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s", av[i]);
		if (av[i + 1])
			printf(" ");
		i++;
	}
	printf("\n");

	return (0);
}
