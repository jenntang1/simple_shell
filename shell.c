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
	char *prompt = "jj$";
	
	while (1)
	{
		write(STDOUT_FILENO, *prompt, 3);
	}
}
