B#include "simpleshell.h"

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
	int buff = 0;
	int status = 0;
	char *updpath;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		write(1, "jj$", 3);
		status = getline(&line, &buff, stdin);
		if (status == -1)
		{
			if (isatty(STDIN_FILENO) == 0)
			{
				write(1, shell, strlen(shell));
				write(1, ": File name too long", 20);
				continue;
			}
			if (isatty(STDIN_FILENO) == 1)
			{
				write(1, "\n", 1);
				break;
			}
			if (line[status - 1] == '\n')
				line[status - 1] == '\0';
			if (*s == '\0')
				continue;
		}

		if (builtin_helper(line) == -1)
		{
			updpath = pathfinder(line);
			execute(updpath);
		}
	}
	free_list(list_t head);
	free(status);
	free(updpath)
	return (0);
}
