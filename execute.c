#include "simpleshell.h"

/**
 * execute - function that executes a program
 * @argv: arguments
 * Return: 0
 */
int execute(char **argv)
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
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
			return (-1);
		}
		else
		execve(argv[0], argv, NULL);
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
