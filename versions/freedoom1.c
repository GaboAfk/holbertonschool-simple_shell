#include "zzz.h"

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


int buff_cleaner(char *buffer)
{
	int i = 0, buf_len;

	if (!*buffer)
		return (-2);

	while (buffer[i])
	{
		printf("buffer[%d] = %c\n", i, buffer[i]);
		if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
		{
			i++;
			printf("i = %d\n", i);
		}
			
		else
			break;
	}

	buf_len = strlen(buffer);

	printf("buf_len = %d i = %d\n", buf_len, i);

	if (i >= buf_len)
		return (-1);
//	printf("sali del whle\n");

	if (buffer[buf_len - 1] == '\n')
		buffer[buf_len - 1] = '\0';

//	buffer = &(buffer[i]);
/*
	if (strncmp(&buffer[i], "exit\0", 5) == 0)
		return (-1);

	if (strncmp(&buffer[i], "env\0", 4) == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		return (2);
	}
*/
	return (0);
}

void children_maker(char *command, char **array)
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
		if (execve(command, array, environ) == -1)
			perror("Error");
	}
	else
		wait(&status);
}

int spc_cmd(char *cmd, int cmd_count)
{
	int i;

	if (strncmp(cmd, "exit", 4) == 0 && cmd_count == 1)
		return (1);

	if (strncmp(cmd, "env", 3) == 0 && cmd_count == 1)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
	}
	return (0);
}