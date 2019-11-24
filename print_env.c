#include "simpleshell.h"

int main(void)
{
	int i;

	char **array = _printenv(__environ);

	for (i = 0; array[i] != NULL; i++)
		printf("%s\n", array[i]);
	return (0);
}

/**
 * _printenv - function that prints environ
 * @str: array of strings
 * Return: array of strings
 */
char **_printenv(char **str)
{
	int i;

	for (i = 0; __environ[i] != NULL; i++)
	{
		str[i] = __environ[i];
	}
	return (str);
}
