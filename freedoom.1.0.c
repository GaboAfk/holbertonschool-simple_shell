#include "zzz.h"

/**
 * sigint_handler - rompenachos
 * @signum: signum
 */
void sigint_handler(int signum)
{
	(void)signum;
	printf("No tan rapido amigo GGizi\n");
}

/**
 * array_in_free - free an array
 * @arr: entry array of strings
 */

void array_in_free(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr && arr[i]; i++)
		free(arr[i]);
	free(arr);
	arr = NULL;
}

/**
 * buff_cleaner - clears the buffer in case of spaces, tabs or new lines only
 * @buffer: entry array or input prompt
 * Return: 0 Success other if fails
 */

int buff_cleaner(char *buffer)
{
	int i = 0, buf_len;

	if (!*buffer)
		return (-2);

	while (buffer[i])
	{
		if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
			i++;
		else
			break;
	}

	buf_len = strlen(buffer);

	if (i >= buf_len)
		return (-1);

	if (buffer[buf_len - 1] == '\n')
		buffer[buf_len - 1] = '\0';

	return (0);
}

/**
 *children_maker - creates a child procces of the program
 *@command: entry string or path to execute
 *@array: entry command and flags
 *@env: environ variables
 */

void children_maker(char *command, char **array, char **env)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return;
	}

	if (pid == 0)
	{
		if (execve(command, array, env) == -1)
			perror("Error");
	}
	else
		wait(&status);
}

/**
 * spc_cmd - checks if input promt is exit or print env
 * @cmd: entry string or input prompt
 * @cmd_count: n°of commands or arguments
 * Return: 1 if is exit 0 if not
 */

int spc_cmd(char *cmd, int cmd_count)
{
	int i;

	if (strncmp(cmd, "exit", 4) == 0 && cmd_count == 1)
	{
		/*/if (errno != 127 && errno != 0)/*/
		/*/	errno = 2;/*/
		/*/else if (errno != 127 && errno != 2)/*/
		/*/	errno = 0;*/
		return (1);
	}

	if (strncmp(cmd, "env", 3) == 0 && cmd_count == 1)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return (1);
	}
	return (0);
}
