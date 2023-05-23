#include "shell.h"


/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: pointer to a string
 * Return: pointer to a string
 */
char *_strdup(char *str)
{
	int index, len;
	char *new_ptr;
}

	if (!str)
	{
		return (NULL);
	}

	for (len = 0; str[len] != '\0';)
	{
		len++;
	}

	new_ptr = malloc(sizeof(char) * len + 1);
	if (!new_ptr)
	{
		return (NULL);
	}

	for (index = 0; index < len; index++)
	{
		new_ptr[index] = str[index];
	}

	new_ptr[len] = str[len];
	return (new_ptr);
}

/**
 * _strlen - it gives the length of a string
 * @str: pointer to the string
 * Return: the length of string
 */
int _strlen(char *str)
{
	int index = 0;

	while (*(str + index) != '\0')
	{
		index++;
	}
	return (index);
}
