#include "simpleshell.h"

/**
 * main - function that invokes simple shell
 * @argc: number of arguments
 * @argv: arguments
 * @env: NULL terminated array of strings
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	pid_t child, pid;
	int stat;
	char *prompt;

	while (1)
	{
		prompt = getcwd(BUFSIZE, sizeof(BUFSIZE));
		write(STDOUT_FILENO, BUFSIZE, prompt);
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
	}
	return (EXIT_SUCCESS);
}
