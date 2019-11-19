#include "simpleshell.h"

/**
 * _strncmp - compares strings upto n chars
 * @s1: string
 * @s2: string
 * @n: num of chars
 * Return: 0 if same non 0 if not
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * getenviron - function to get the PATH in environ
 * @var: PATH
 * Return: memory address of environ
 */
char getenviron(char *var)
{
	int i;

	for (i = 0; environ[i] != NULL; i++);
	{
		if (_strncmp(environ[i], var, _strlen(var)) == 0)
			return (&environ[i]);
		else
			perror("Error");
	}
}
