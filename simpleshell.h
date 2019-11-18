#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);

ssize_t getline_jjsh(char **lineptr, size_t *n, FILE *stream);

#endif /* SIMPLESHELL_H */
