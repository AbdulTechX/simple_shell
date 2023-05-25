#include "shell.h"

/**
 * check_buitin - check if parsed command in built-in
 * @cmd: parsed command to be check
 * Return: 0 success -1 fail
 */
void (*check_builtin(char **cmd))(char **cmd)
{
	int index, alteration;
	mybuiltin T[] = {
		{"exit", exitt},
		{"env", env},
		{NULL, NULL}
	};

	for (index = 0; T[index].path; index++)
	{
		alteration = 0;
		if (T[index].path[alteration] == cmd[0][alteration])
		{
			for (alteration = 0; cmd[0][alteration]; alteration++)
			{
				if (T[index].path[alteration] != cmd[0][alteration])
					break;
			}
			if (!cmd[0][alteration])
				return (T[index].func);
		}
	}
	return (0);
}
