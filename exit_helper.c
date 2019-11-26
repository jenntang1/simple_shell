#include "simpleshell.h"

/**
 * exit_helper - frees and exits shell
 * @head: first node
 * Return: nothing
 */

void exit_helper(list_t *head)
{

	free_list(head);
	exit(EXIT_SUCCESS);
}
