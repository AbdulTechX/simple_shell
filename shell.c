#include "shell.h"

void _EOF(int read_char, char *buffer);
void _isatty(void);
int main(int arc, char **argv);

/**
 * _EOF - handles the End of File.
 * @read_char: return Value of the getline function.
 * @buffer: input to memory.
 */
void _EOF(int read_char, char *buffer)
{
	(void)buffer;
	if (read_char == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}
/**
 * _isatty - verify if terminal
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#simple_shell$ ");
}

/**
 * main - shell entry point.
 * @argc: argument variable
 * @argv: array of argument variable.
 * Return: Always 0 on success.
 */
int main(int argc, char **argv)
{
	char *buffer = NULL, **prompt;
	size_t n = 0;
	ssize_t read_char;

	(void)argc;
	(void)argv;

	/* create an indefinte loop */

	signal(SIGINT, sig_handler);
	while (read_char != EOF)
	{
		_isatty();
		read_char = getline(&buffer, &n, stdin);
		/* check if the getline function fail to reach the EOF or user use Crtl C*/
		_EOF(read_char, buffer);
		prompt = splitstring(buffer, "\n");
		execute(prompt);
	}
	free(buffer);
	free(prompt);

	return (0);
}
