#include "simpleshell.h"

/**
 * builtin_helper - function that calls builtins
 * @s: builtin commands
 * Return: varies depending on check will be int
 */
int builtin_helper(char *s)
{
	if (s == "exit")
		exit_helper();
	if (s == "env")
	{
		print_env("env");
		return (0);
	}
	return (-1);
}
