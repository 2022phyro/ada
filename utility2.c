#include "monty.h"
/**
 * pen - opens and reads the contents of a file
 *
 * @filename: the filename
 * Return: a string containing the read bytes
 */
char *pen(char *filename)
{
	int fd;
	struct stat fdstat;
	size_t size;
	char *buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fstat(fd, &fdstat);
	size = fdstat.st_size;

	buffer = malloc(sizeof(char) * size + 1);

	read(fd, buffer, size);
	close(fd);
	buffer[size] = '\0';
	return (buffer);
}
/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: a pointer to the previously allocated memory
 * @osize: the size of the previously allocated memory
 * @nsize: the size of the memory to be allocated
 *
 * Return: reallocated memory or NULL if malloc fails.
 */
void *_realloc(void *ptr, size_t osize, size_t nsize)
{
	size_t nbytes, b;
	void *buffer;

	if (osize == nsize)
	return (ptr);
	if (!nsize && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (nsize > osize)
		nbytes = osize;
	else
		nbytes = nsize;
	buffer = malloc(nsize);
	if (!buffer)
		return (NULL);
	if (!ptr)
		return (buffer);
	for (b = 0; b < nbytes; b++)
		((char *)buffer)[b] = ((char *)ptr)[b];
	free(ptr);
	return (buffer);
}

