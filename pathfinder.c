char *pathfinder(*line)
{char *path = _strdup(getenviron("PATH"));
	int i = 0, j = 0;
	char *tokens = strtok(path, ":");
	char *token_paths = [100];
	char *str2 = line;
	char *updpath = NULL;
	updpath = malloc (sizeof(char) * 100);

	while (tokens != NULL)
	{
		token_array[i] = tokens;
		i++;
	}
	token_paths[i] = "NULL";
	while (token_paths[j] != "NULL")
	{
		_strcpy(updpath,token_array[j]);
		_strcat(updpath, "/");
		_strcat(updpath, s2);
		_strcat(updpath, "\0");
			}
	}
}
