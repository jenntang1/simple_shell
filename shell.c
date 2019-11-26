#include "simpleshell.h"

/**
 * main - function that invokes simple shell
 * @argc: number of arguments
 * @argv: arguments
 * @envp: NULL terminated array of strings
 * Return: 0
 */

int main(int argc, char **argv, char **envp)
{
	char *updpath;
	char *line = NULL;
	char *cmd = NULL;
	char *shell = argv[0];
	size_t buff = 0;
	ssize_t status = 0;
	char **tokens = NULL;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "$ ", 2);
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
