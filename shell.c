#include "simpleshell.h"

char *shell = *argv[0];
/**
 * main - function that invokes simple shell
 * @argc: number of arguments
 * @argv: arguments
 * @env: NULL terminated array of strings
 * Return: 0
 */

int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	buff = 0;
	int status = 0;


	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		write(1, "jj$", 3);
		if (isatty(STDIN_FILENO) == 0)
		{
			write(1,"\n", 1);
		break;
		}
		status = getline(&line, &buff, stdin);
		if (status == -1)
		{
			write(1,shell,strlen(shell));
			write(1,": File name too long". 20);
			continue;
		}


	}
}
