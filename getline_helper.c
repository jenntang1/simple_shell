#include "simpleshell.h"

/**
 * getline_helper - function to read a line
 * @line: line from stdin
 * Return: number of chars read
 */
int getline_helper(char *line)
{
	char buf[BUFSIZE];
	size_t num;

	num = getline(&line, &buf, stdin);
	return (num);
}
