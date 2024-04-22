#include "zzz.h"


int array_in_free(char **arr)
{
	int i, exit_val = 1;

	if (!arr)
		return (-1);

	if (arr[1])
		exit_val = atoi(arr[1]);

	for (i = 0; arr && arr[i]; i++)
		free(arr[i]);
	free(arr);
	arr = NULL;

	return (exit_val);
}
int _isdigit(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (i);
}

/*void free_all(char **arr, char *buff)
{
	if (!arr || !buff)
		return;

	array_in_free(arr);
	free(buff);
	buff = NULL;
}*/

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

int spc_cmd(char **array_cmd, int cmd_count)
{
	int i;

	if (strncmp(array_cmd[0], "exit", 4) == 0)
		if (cmd_count == 1 || (cmd_count == 2 && _isdigit(array_cmd[1])))
			return (1);

	if (strncmp(array_cmd[0], "env", 3) == 0 && cmd_count == 1)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
	}

	if (strncmp(array_cmd[0], "cd", 2) == 0 && cmd_count == 2)
	{
//		printf("strncmp cmd = %s\n", array_cmd[0]);
//		cmd = cmd + 3;
//		printf("cmd++ =%s\n", cmd);

		if (chdir(array_cmd[1]) == 0)
		{
		//	printf("me movi al dir cmd[1] =%s\n", array_cmd[1]);
			return (2);
		}
//		else
//			return (2);
	}

	return (0);
}
