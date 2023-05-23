#include "shell.h"

/**
 * _strlen - function that counts the length of a string
 * @s: string input
 * Return: length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

/**
 * _strdup - duplicate a string
 * @str: string
 * Return: duplicated string or Null if failed
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	if (!str)
	{
		return (NULL);
	}
	for (len = 0; str[len] != '\0';)
	{
		len++;
	}
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}
	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}
	return (str2);
}
