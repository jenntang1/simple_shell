#include "simpleshell.h"

/**
 * builtin_helper - function that calls builtins
 * @s: builtin commands
 * Return: varies depending on check will be int
 */
int builtin_helper(char *s, list_t *head)
{

	char *ex = "exit";
	char *en = "env";

	if (_strncmp(s , ex , 6) == 0)
		exit_helper(head);
	if (_strncmp(s, en, 5) == 0)
	{
		_printenv("env");
		return (0);
	}
	return (-1);
}
