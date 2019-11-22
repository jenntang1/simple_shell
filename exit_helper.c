#include "simpleshell.h"

/**
 * exit_helper - function that calls exit
 * @args: exit
 * Return: nothing
 */
int exit_helper(char **args)
{
	if (args[0] == "exit")
		exit(EXIT_SUCCESS);
}
