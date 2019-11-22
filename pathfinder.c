#include "simpleshell.h"


int main(int argc,char ** argv, char **env)
{
	char *string = "Hello";

	pathfinder(string);

	return (0);
}

/**
 * pathfinder - function that finds the 
 * @line: 
 * Return: 
 */
void pathfinder(char *line)
{
	char *path = NULL;
	int i = 0, j = 0;
	char **tokens;
	char *token_paths[100];
	char *str2 = line;
	char *updpath = NULL;

	updpath = malloc(sizeof(char) * 100);
/*	if (updpath == NULL)
		return (NULL); */
	path = _strdup(getenviron("PATH"));
	while (tokens != NULL)
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
		printf("%s\n", updpath);
	}
}
