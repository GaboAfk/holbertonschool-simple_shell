/*
* File: holyshell.c
* Auth: Gabriel Morffe, Joaquin Aguilar
*/

#include "zzz.h"


/**
 * sigint_handler - rompenachos
 * @signum: signum
 */
void sigint_handler(int signum)
{
	(void)signum;
	//printf("\b\b  \n");
	printf("No tan rapido amigo GGizi\n");
	//printf("%s%s%s%s%s#holy$hel%s ", INVRT, BOLD, BLINK, YELLOW, BG_CYAN, RESET);
}

/*struct termios original_termios;
void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}*/

/**
 * main - simple_shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *buffer = NULL; // **array_str = NULL, 
	char **array_multi = NULL, *cp_buffer = NULL;
	size_t bufsiz = 0;
	int err, buf_st, multi_str, i;
	//int cmd_count, spc_val, 
	int gnl_val;
	

	signal(SIGINT, sigint_handler);
	while (1)
	{
		printf("%s%s%s%s%s#holy$hell%s ", INV, BOLD, BLINK, YELLOW, BG_CYAN, RESET);
		err = getline(&buffer, &bufsiz, stdin);
		if (err == -1)
		{
			free(buffer);
			break;
		}
		buf_st = buff_cleaner(buffer);
		if (buf_st < 0)
		{
			free(buffer), buffer = NULL;
			continue;
		}
		cp_buffer = strdup(buffer);
		multi_str = split_str2(&array_multi, cp_buffer, ";");
		free(cp_buffer);
		if (!multi_str)
		{
			gnl_val = general_function(array_multi, buffer, " ");
			//if(gnl_val == 1)
			//		continue;
		}
		else
		{
			for (i = 0; i < multi_str; i++)
			{
				gnl_val = general_function(array_multi, array_multi[i], " ");
				if(gnl_val == 1)
					continue;
				//else if(gnl_val == 2)
				//	continue;
			}
			
		}
		

		//for (i = 0; i < multi_str; i++)
		//{
		/*	cmd_count = split_str2(&array_str, buffer, " ");

			spc_val = spc_cmd(array_str, cmd_count);
			if (spc_val == 1)
				free(buffer), buffer = NULL, exit(array_in_free(array_str));
			else if (spc_val > 1)
			{
				free(buffer), buffer = NULL, array_in_free(array_str);
				continue;
			}

			if (get_dir(&array_str[0]) == 1)
				children_maker(array_str[0], array_str);
			else
				perror("Error");
			array_in_free(array_str), free(buffer), buffer = NULL;*/
		//}
		//array_in_free(array_str);
		array_in_free(array_multi), free(buffer), buffer = NULL;
	}
	return (0);
}
