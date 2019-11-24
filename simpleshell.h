#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#define BUFSIZE 1024

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

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
int _strlen(char *s);

char *pathfinder(char *line);
char *getenviron(char *var);

char **_printenv(char **str);
int exit_helper(char **args);

int execute(char **argv);

#endif /* SIMPLESHELL_H */
