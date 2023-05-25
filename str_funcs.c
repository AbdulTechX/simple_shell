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

/**
 * concat_all - concats 3 strings in a newly allocated memory
 * @str1: first string
 * @str2: second string
 * @str3: Third string
 * Return: pointer to the new string
 */
char *concat_all(char *str1, char *str2, char *str3)
{
	char *ret;
	int l1, l2, l3, i, k;

	l1 = _strlen(str1);
	l2 = _strlen(str2);
	l3 = _strlen(str3);

	ret = malloc(l1 + l2 + l3 + 1);
	if (!ret)
		return (NULL);

	for (i = 0; str1[i]; i++)
		ret[i] = str1[i];
	k = i;

	for (i = 0; str2[i]; i++)
		ret[k + i] = str2[i];
	k = k + i;

	for (i = 0; str3[i]; i++)
		ret[k + i] = str3[i];
	k = k + i;

	ret[k] = '\0';

	return (ret);
}
