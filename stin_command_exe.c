#include "shell.h"

void sig_handler(int sig);

/**
 * sig_handler - check if Ctrl C is pressed
 * @sig: int.
 */
void sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		_puts("\n#simple_shell$ ");
	}
}
