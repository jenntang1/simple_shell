#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#define BUFSIZE 1024

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
char *getenviron(char *var);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
char *getline_helper(char *line);
int exit_helper(char **args);
char *pathfinder(char *line);

#endif /* SIMPLESHELL_H */
