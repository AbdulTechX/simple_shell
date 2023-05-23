#include "shell.h"


char **splitstring(char *str, const char *delim);
void execute(char **argv);

/**
 * splitstring - splits a string and makes it an array of pointers to words
 * @str: the string to be split
 * @delim: The delimeter
 * Return: array of pointers to words.
*/
char **splitstring(char *str, const char *delim)
{
	int count_tokens;
	char *token_store;
	int i;
	char **argv;
	char *buffer_copy;

	buffer_copy = malloc(_strlen(str) + 1);
	if (buffer_copy == NULL)
	{
		perror("Error:");
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		buffer_copy[i] = str[i];
		i++;
	}
	buffer_copy[i] = '\0';
	token_store = strtok(buffer_copy, delim);
	argv = malloc((sizeof(char *) * 2));
	argv[0] = _strdup(token_store);

	i = 1;
	count_tokens = 3;
	while (token_store)
	{
		token_store = strtok(NULL, delim);
		argv = _realloc(argv, (sizeof(char *) * (count_tokens - 1)), (sizeof(char *) * count_tokens));
		argv[i] = _strdup(token_store);
		i++;
		count_tokens++;
	}
	free(buffer_copy);
	return (argv);
}

/**
 * execute - execute command
 * @argv: array of argument.
*/
void execute(char **argv)
{
	int d, status;

	if (!argv || !argv[0])
		return;
	d = fork();
	if (d == -1)
	{
		perror("Error:");
	}
	if (d == 0)
	{
		execve(argv[0], argv, NULL);
			perror("./hsh");
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
