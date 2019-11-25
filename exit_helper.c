#include "simpleshell.h"

/**
 * exit_helper - frees and exits shell
 *
 * Return: nothing
 */
void exit_helper(void)
{
	free_list(*head);
	exit(EXIT_SUCCESS);
}
