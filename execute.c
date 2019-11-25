#include "simpleshell.h"

/**
 * execute - function that executes a program
 * @argv: arguments
 * @line: command
 * Return: 0
 */
int execute(char **argv, char *line)
{
	pid_t child, pid;
	int stat;
	char *prompt = "jj$";

	child = fork();
	if (child == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (child == 0)
	{
		if (execve(list_t updpath->str, *line, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
			return (-1);
		}
		else
			execve(list_t updpath->str, *line, NULL);
	}
	else
	{
		do {
			pid = waitpid(child, &stat, WUNTRACED);
			if (pid == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
				return (-1);
			}
		} while (!WIFEXITED(stat));
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
