#include "shell.h"


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
int main(void)
{

	char *buffer = NULL, *ret, *path_name, **prompt;
	size_t n = 0;
	ssize_t read_char;
	list_t *head = '\0';
	void (*arc)(char **);

	/* create an indefinte loop */

	signal(SIGINT, sig_handler);
	while (read_char != EOF)
	{
		_isatty();
		read_char = getline(&buffer, &n, stdin);
		/* check if the getline function fail */
		_EOF(read_char, buffer);
		prompt = splitstring(buffer, "\n");
		if (!prompt || !prompt[0])
			execute(prompt);

		else
		{
			ret = _getenv("PATH");
			head = path_fill(ret);
			path_name = _which(prompt[0], head);
			arc = check_builtin(prompt);
			if (arc)
			{
				free(buffer);
				arc(prompt);
			}
			else if (!path_name)
				execute(prompt);
			else if (path_name)
			{
				free(prompt[0]);
				prompt[0] = path_name;
				execute(prompt);
			}
		}

	}
	free(buffer);
	free_prompt(prompt);
	free_list(head);
	return (0);
}
