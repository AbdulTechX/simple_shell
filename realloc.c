#include "shell.h"

/**
 * _realloc - Reallocates memory block
 * @ptr: previous pointer
 * @old_size: old size of previous pointer
 * @new_size: new size for our pointer
 * Return: New resized Pointer
 */

void *_realloc(void *ptr, unsigned int size_t, unsigned int n_size)
{
	char *new_ptr;
	char *old_ptr;

	unsigned int i;

	if (ptr == NULL)
		return (malloc(n_size));

	if (n_size == size_t)
		return (ptr);

	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(n_size);
	old_ptr = ptr;
	if (new_ptr == NULL)
		return (NULL);

	if (n_size > size_t)
	{
		for (i = 0; i < size_t; i++)
			new_ptr[i] = old_ptr[i];
		free(ptr);
		for (i = size_t; i < n_size; i++)
			new_ptr[i] = '\0';
	}

	if (n_size < size_t)
	{
		for (i = 0; i < n_size; i++)
			new_ptr[i] = old_ptr[i];
		free(ptr);
	}

	return (new_ptr);
}

