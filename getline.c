#include "simpleshell.h"

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strlen(char *s);

/**
 * getline_jjsh - function that reads an entire line from stream
 * @lineptr: stores the address of the buffer containing text
 * @n: size in bytes of lineptr
 * @stream: stream where text resides
 * Description: 4. Simple shell 0.1.1
 * Return: see below
 * 1. Upon success, number of chars read including delimiter ('\n') but not null byte
 * 2. Upon fail, -1 to read a line including EOF
 */
ssize_t getline_jjsh(char **lineptr, size_t *n, FILE *stream)
{
	char buf[1024];
	size_t n_read = _strlen(*lineptr);
	size_t buf_read = _strlen(buf);

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	if (*lineptr == NULL || *n < sizeof(buf))
		*n = sizeof(buf);
		if ((*lineptr = malloc(*n)) == NULL)
			return (-1);
	*lineptr[0] = '\0';
	while (stream != NULL)
	{
		if (*n - n_read < buf_read)
		{
			if (*lineptr > buf)
				return (-1);
			else
				*n *=2;
			if ((*lineptr = _realloc(*lineptr, n_read, *n)) == NULL)
				return (-1);
		}
		_memcpy(*lineptr + n_read, buf, buf_read);
		n_read += buf_read;
		*lineptr[n_read] = '\0';
		if (*lineptr[n_read -1] == '\n')
			return (n_read);
	}
	return (-1);
}	
	
/*{
	static size_t alloc1 = 16, alloc2 = 16;
	ssize_t numchars = 0;
	size_t c, n_alloc;
	char *temp;

	if ((lineptr == NULL) || (n == NULL) || (stream == NULL))
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(alloc1);
		if (*lineptr == NULL)
			return (-1);
		else
			*n = alloc1;
	}
	else
	{
		while (!EOF)
		{
			numchars++;
			if (numchars >= *n)
			{
				n_alloc = *n + alloc2;
				temp = _realloc(*lineptr, *n, n_alloc + 1);
				if (temp != NULL)
				{
					*lineptr = temp;
					*n = n_alloc;
				}
				else
					return (-1);
			*lineptr[numchars - 1] = c;
			if (c == '\n')
				break;
			}
		}
		if (c == EOF)
			return (-1);
	}
	*lineptr[numchars] = '\0';
	return (numchars);
}*/
