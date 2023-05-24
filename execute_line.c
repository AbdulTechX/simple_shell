#include "shell.h"

/**
 * execute - execute command
 * @argv: array of argument.
*/
void execute(char **argv)
{
	int status;
	pid_t child_pid;

	if (!argv || !argv[0])
		return;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror(_getenv("_"));
	}
	if (child_pid == 0)
	{
		execve(argv[0], argv, NULL);
			perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&status);
}
