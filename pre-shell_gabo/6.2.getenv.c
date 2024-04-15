#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern char **environ;

/**
 * _getenv - search PATH @name in environ
 * @name: PATH to find
 * Return: PATH of @name or NULL.
 */
char *_getenv(const char *name)
{
    char **env = environ;
    int i = 0;
    size_t name_length = strlen(name);

    printf("name = %s\n", name);
    printf("name_length = %ld\n", name_length);
    while (env[i])
    {
        printf("env[%d] = %s\n", i, env[i]);

        if (strncmp(env[i], name, name_length) == 0 && (env[i])[name_length] == '=')
            return (&((env[i])[name_length + 1]));
        i++;
    }
    return (NULL);
}

/**
 * main - prints the path of @name in environ
 * @ac: number of args
 * @av: args
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    char *path;
    
    if (ac < 2)
    {
        printf("Usage: %s name_of_var_to_find ...\n", av[0]);
        return (1);
    }
    
    path = _getenv(av[1]);

    printf("_getenv\n");
    path ? printf("%s\n", path) : printf("PATH not found\n");

    path = getenv(av[1]);

    printf("getenv\n");
    path ? printf("%s\n", path) : printf("PATH not found\n");
    
    return (0);
}