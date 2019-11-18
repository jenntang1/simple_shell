#include "simpleshell.h"

/**
 * _strncmp - compares strings upto n chars
 * @s1: string
 * @s2: string
 * @n: num of chars
 *
 * Desripttion: compares strings
 *
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
