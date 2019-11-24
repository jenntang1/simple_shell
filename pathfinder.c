#include "simpleshell.h"

/**
 * pathfinder - function that finds the path
 * @line: command
 * Return: path of the command
 */
char *pathfinder(char *line)
{
	char *path = NULL;
	int i = 0, j = 0;
	char **tokens;
	char *token_paths[100];
	char *str2 = line;
	char *updpath = NULL;

	updpath = malloc(sizeof(char) * 1024);
	if (updpath == NULL)
		return (NULL);
	path = _strdup(getenviron("PATH"));
	while (token_paths[i] != NULL)
	{
		*tokens = strtok(path, ":");
		token_paths[i] = *tokens;
		i++;
	}
	token_paths[i] = NULL;
	while (token_paths[j++])
	{
		_strcpy(updpath, token_paths[j]);
		_strcat(updpath, "/");
		_strcat(updpath, str2);
		_strcat(updpath, "\0");
		if (access(updpath, X_OK) == 0)
			break;
	}
	return (updpath);
}
