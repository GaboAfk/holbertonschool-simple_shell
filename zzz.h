#ifndef SHLL
#define SHLL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
char **split_str(char *buffer, char *delim);
char *_getenv(char *name);
void get_dir(char **function);

#endif
