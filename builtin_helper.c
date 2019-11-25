#include "simpleshell.h"

/**
 * builtin_helper - function that calls builtins
 * @line: exit
 * Return: varies depending on check will be int
 */
int builtin_helper(char *s)
{
	if (s == "exit")
		exit(EXIT_SUCCESS);
	if (s == "env")
	{
		print_env("env");
		return (0);
	}
	return (-1);
}
