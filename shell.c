#include "simpleshell.h"

/**
 * main - function that invokes simple shell
 * @argc: number of arguments
 * @argv: arguments
 * @env: NULL terminated array of strings
 * Return: 0
 */

int main(int __attribute__((unused)) argc, char **argv, char **envp)
{
	char *line = NULL;
	size_t buff = 0;
	char *updpath;
	ssize_t status = 0;
	char *cmd = NULL;
	char *shell = argv[0];
	char **tokens = NULL;

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
		}
		tokens = strtok_helper(line, " ,\n");
		cmd = tokens[0];
		updpath = pathfinder(cmd);
		if (builtin_helper(cmd, NULL) == -1)
		{
			execute(updpath, tokens, envp);
		}
	}
	free(line);
	free(tokens);
	return (0);
}
