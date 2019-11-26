#include "simpleshell.h"

/**
 * builtin_helper - function that calls builtins
 * @s: builtin commands
 * Return: varies depending on check will be int
 */
int builtin_helper(char *s, list_t *head)
{
	if (s == "exit")
		exit_helper(head);
	if (s == "env")
	{
		_printenv("env");
		return (0);
	}
	return (-1);
}
