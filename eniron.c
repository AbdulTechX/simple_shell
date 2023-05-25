#include "shell.h"


/**
 * env - prints the current environment
 * @argv: array of arguments
 */
void env(char **argv __attribute__ ((unused)))
{

	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_puts("\n");
	}

}
