#ifndef SHLL
#define SHLL

#define BOLD "\033[1m"
#define BLINK "\033[6m"
#define INVERT "\033[7m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define BG_CYAN "\033[46m"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>


extern char **environ;
char **split_str(char *buffer, char *delim);
char *_getenv(char *name);
int get_dir(char **function);
void array_in_free(char **arr);
int buff_cleaner(char *buffer);
void children_maker(char *command, char **array);

#endif
