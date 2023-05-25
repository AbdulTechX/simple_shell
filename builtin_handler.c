#include "shell.h"

/**
 * exitt - exits the shell with or without a return of status n
 * @argv: array of words of the entered line
 */
void exitt(char **argv)
{
	int index, num;

	if (argv[1])
	{
		num = _atoi(argv[1]);
		if (num <= -1)
			num = 2;
		free_prompt(argv);
		exit(num);
	}
	for (index = 0; argv[index]; index++)
		free(argv[index]);
	free(argv);
	exit(0);
}
