#include "simpleshell.h"

/**
 * free_list - frees linked list
 * @head: head
 */
void free_list(list_t *head)
{
	if (head)
	{
		free(head->str);
		free_list(head->next);
		free(head);
	}
}
