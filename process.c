#include "simpleshell.h"

/**
 * process - function for creating & executing processes
 * @argv: arguments
 * Return:
 */
int process(char **argv)
{
	/* declare variables for child & parent processes */
	pid_t child, pid;
	/* declare variable for wait */
	int stat;
	/* fork to create a child process */
	child = fork();
	/* if fork fails, print error */
	if (child == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	/* child process will execute */
	if (child == 0)
	{	/* if execve fails, print error and exit */
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
			return (-1);
		}
		else /* otherwise call execve */
			execve(argv[0], argv, NULL);
	}
	else /* parent process will wait */
	{
		do {
			pid = waitpid(child, &stat, WUNTRACED);
			if (pid == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
				return (-1);
			}
		}
		while (!WIFEXITED(stat))
		exit(EXIT_SUCCESS);
	}
	return (1);
}
