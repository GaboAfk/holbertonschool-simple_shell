#include <stdio.h>

extern char **environ;

/**
 * main - prints the address of env and environ
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    printf("Address of env = %p\n", (void*)&env);
    printf("Address of environ = %p\n", (void*)&environ);

    return (0);
}