#include "shell.h"

/**
 * _getenv - Gets the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *_getenv(const char *name)
{
	int index;
	int alt;
	char *cmd;

	if (!name)
		return (NULL);
	for (index = 0; environ[index]; index++)
	{
		alt = 0;
		if (name[alt] == environ[index][alt])
		{
			while (name[alt])
			{
				if (name[alt] != environ[index][alt])
					break;
				alt++;
			}
			if (name[alt] == '\0')
			{
				cmd = (environ[index] + alt + 1);
				return (cmd);
			}
		}
	}
	return (0);
}
