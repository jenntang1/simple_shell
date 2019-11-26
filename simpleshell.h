#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct list_s - single linked list
 * @str: string
 * @next: points to next node
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

char **strtok_helper(char *line, char *delim);
void free_list(list_t *head);
char *_realloc(char *ptr, int old_size, int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);

char *pathfinder(char *cmd);
char *getenviron(char *var);

void _printenv(char *s);
void exit_helper(list_t *head);
int builtin_helper(char *s, list_t *head);
int execute(char *argv, char **tokens, char **__environ);

#endif /* SIMPLESHELL_H */
