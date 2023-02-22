#include "shell.h"
#include <stdlib.h>

/**
 * bfree - frees a pointer and inilializes it to null
 * @ptr: pointer to pointer to free
 *
 * Return: 1 if successful, 0 if not
 */
int bfree(void **ptr)
{

	if (ptr && *ptr)
	{

		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
