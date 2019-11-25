#include "simpleshell.h"

/* int main(void)
{
	int i;

	char **array = _printenv(__environ);

	for (i = 0; array[i] != NULL; i++)
		printf("%s\n", array[i]);
	return (0);
} */

/**
 * _printenv - function that prints environ
 * @str: array of strings
 * Return: array of strings
 */
void **_printenv(*s)
{
	int i = 0;

	while (s)
	{
		write(1, s, _strlen(s));
		write(1, "\n", 1);
		s =  __environ[++i];
	}
}
