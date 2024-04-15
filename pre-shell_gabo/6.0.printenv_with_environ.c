#include <stdio.h>

extern char **environ;
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(void)
{
    int i = 0;
    char **env = environ;

    while (env[i])
    {
        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}