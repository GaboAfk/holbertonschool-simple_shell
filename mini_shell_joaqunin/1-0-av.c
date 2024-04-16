#include <stdio.h>

/**
 *
 *
 */

int main (int argc, char *argv[])
{
	int c = 0;
	if (argc)
	{
		while (argv)
		{
			printf("Arguments of the programs are %s\n", argv[c]);
			c++;
		}
	}
}
