#include "shell.h"
#include <stdlib.h>

/**
 * _memset -fills memory with a constant byte
 * @s: pointer to memory area
 * @b: the bytes to fill *s with
 * @n: the amount of bytes to be filled
 *
 * Return: (s) a pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees an array of strings
 * @pp: array of strings
 *
 * Return: None
 */
void ffree(char **pp)
{

	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 *_realloc - reallocates memory using malloc and free
 * @new_size: size of new memory allocation
 * @ptr: pointer to the memory block to be reallocated
 * @old_size: byte size of previous block
 *
 * Return: pointer to reallocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{

	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
