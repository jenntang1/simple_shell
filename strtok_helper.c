#include "simpleshell.h"

/**
 * strtok_helper - function that splits a line
 * @line: line from getline_helper
 * Return: token
 */
char strtok_helper(char *line)
{
	char delim[] = " \t";
	char *tok = strtok(line, delim);

	while (tok != NULL)
		tok = strtok(NULL, delim);
	return (tok);
}
