/*
* File: holyshell.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/

#include "zzz.h"

/**
 * split_str - split an str
 * @buffer: entry string
 * Return: an array of each words of str
 */
/*
char **split_str(char *buffer, char *delim)
{
	char *token, *cp_buffer;
	char **array;
	int words = 0, i = 0, j;

	if (!buffer)
		return (NULL);

	cp_buffer = strdup(buffer);
	if (!cp_buffer)
		return (NULL);

	token = strtok(buffer, delim);

	while (token)
	{
		words++;
		token = strtok(NULL, delim);
	}

	array = malloc((words + 1)  * sizeof(char *));
	if (!array)
	{
		free(cp_buffer);
		return (NULL);
	}

	token = strtok(cp_buffer, delim);

	while (token)
	{
		array[i] = strdup(token);
		if (!array[i])
		{
			array_in_free(array);
			
			for (j = 0; j < i; j++)
				free(array[j]);

			free(array);
			free(cp_buffer);
			printf("Error copy into array\n");
			return (NULL);
		}

		token = strtok(NULL, delim);
		i++;
	}

	array[words] = NULL;
	free(cp_buffer);
	return (array);
}
*/

/**
 * split_str - split an str
 * @buffer: entry string
 * Return: an array of each words of str
 */
int split_str2(char ***array, char *buffer, char *delim)
{
	char *token, *cp_buffer;
	//char **array;
	int words = 0, i = 0;
	//int j;

//printf("*array = %p buffer = %s delim = %s\n", (void *)*array, buffer, delim);

	if (!buffer)
		return (0);

	cp_buffer = strdup(buffer);
	if (!cp_buffer)
		return (0);

	token = strtok(buffer, delim);

	while (token)
	{
		words++;
		token = strtok(NULL, delim);
	}
//printf("*array = %p cp_buffer = %s words = %d\n", (void *)*array, cp_buffer, words);


//printf("*array = malloc((words + 1)  * sizeof(char *));\n");
	*array = malloc((words + 1)  * sizeof(char *));
	if (!array)
	{
		free(cp_buffer);
		return (0);
	}

//printf("*array = %p cp_buffer = %s words = %d\n", (void *)*array, cp_buffer, words);

//printf("token = strtok(cp_buffer, delim);\n");
	token = strtok(cp_buffer, delim);

	while (token)
	{
		(*array)[i] = strdup(token);
		//printf("*array[i] = strdup(token);\n");
		if (!(*array)[i])
		{
			array_in_free(*array);
			
			/*for (j = 0; j < i; j++)
				free(array[j]);

			free(array);*/
			free(cp_buffer);
			printf("Error copy into array\n");
			return (0);
		}
		//printf("token = strtok(NULL, delim);\n");
		token = strtok(NULL, delim);
		i++;
	}

	//printf("*array[words] = NULL;\n");
	(*array)[words] = NULL;
	//printf("free(cp_buffer);\n");
	free(cp_buffer);
	//printf("return (i);\n");
	return (i);
}




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
 * main - simple_shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL;
	char **array_str = NULL;
	size_t bufsiz = 0;
	int err, i = 0;
	//int status, valid;
	//int buf_len;
	int buf_st;
	//struct stat st;
	//pid_t pid;
	int cmd_count;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		printf("%s%s%s%s%s#holy$hel%s ", INVERT, BOLD, BLINK, YELLOW, BG_CYAN, RESET);

		err = getline(&buffer, &bufsiz, stdin);

		if (err == -1)
		{
			printf("EOF break\n");
			free(buffer);
			break;
		}

		buf_st = buff_cleaner(buffer);
		if (buf_st < 0)
		{
			printf("no hay palabras\n");
			free(buffer);
			buffer = NULL;
			continue;
		}
		

/*
		buf_len = strlen(buffer);
		if (buffer[buf_len - 1] == '\n')
			buffer[buf_len - 1] = '\0';

		printf("buffer = %s buf_len = %d\n", buffer, buf_len);

		if (strncmp(buffer, "exit", 4) == 0 || strncmp(buffer, "EOF", 3) == 0)
		{
			free(buffer);
			exit(-1);
		}
*/
		
		
		printf("buffer = %s\n", buffer);
		cmd_count = split_str2(&array_str, buffer, " ");
		//array_str = malloc(2 * sizeof(char *));
		//array_str[0] = strdup(buffer);
		//array_str[1] = NULL;

		/*if (!commands)
		{
			printf("no commands\n");
			free(buffer);
			buffer = NULL;
			continue;
		}*/
		
		printf("commands = %d\n", cmd_count);


		printf("pre array_str[%d] = %s\n", 0, array_str[0]);

		
		if (spc_cmd(array_str[0], cmd_count))
		{
			printf("spc_cmd\n");
			array_in_free(array_str);
			free(buffer);
			buffer = NULL;
			exit(1);
		}


		/*get_dir(&array_str[0]);

		i = 0;
		while (array_str && array_str[i])
		{
			printf("post array_str[%d] = %s\n", i, array_str[i]);
			i++;
		}*/

		/*if (strncmp(array_str[0], "env", 3) == 0)
		{
			for (i = 0; environ[i]; i++)
				printf("%s\n", environ[i]);
			break;
		}*/

		printf("array_str[%d] = %s\n", 0, array_str[0]);
		if (get_dir(&array_str[0]) == 1)
		{
			for (i = 0; array_str && array_str[i]; i++)
				printf("post array_str[%d] = %s\n", i, array_str[i]);

			children_maker(array_str[0], array_str);
		}
		else
			perror("Error");






		//printf("array_str[0] = %s\n", array_str[0]);
		//printf("array_str[1] = %s\n", array_str[1]);
		/*valid = stat(array_str[0], &st);
		if (valid == 0)
		{
			pid = fork();

			if (pid == -1)
			{
				perror("Error");
				return (1);
			}

			if (pid == 0)
			{
				if (execve(array_str[0], array_str, environ) == -1)
					perror("Error");
			}
			else
				wait(&status);
		}
		else
			perror("Error");*/

		array_in_free(array_str);
		free(buffer);
		buffer = NULL;
	}
	return (0);
}
/*

		i = 0;
		while (array_str && array_str[i])
		{
//			printf("free: array_str[%d] = %s\n", i, array_str[i]);
			free(array_str[i]);
			i++;
		}
//		printf("free: array_str[%d] = %s\n", i, array_str[i]);
		free(array_str[i]);

		if (array_str)
		free(array_str);
		array_str = NULL;

		free(buffer);
		buffer = NULL;
	}
	return (0);
}
*/