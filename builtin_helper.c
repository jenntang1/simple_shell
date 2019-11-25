#include "simpleshell.h"

/**
 * builtin_helper - function that calls builtins
 * @line: exit
 * Return: varies depending on check will be int
 */
int builtin_helper(char *line)
{
	if (args[0] == "exit")
		exit(EXIT_SUCCESS);
	if (args[0] == "env")
	{
		print_env("env");
		return (0);
	}
	return (-1);
}
